/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * 该例程监听tf数据，并计算、发布turtle2的速度指令
 */

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "my_tf_listener");

	// 创建节点句柄
	ros::NodeHandle node;

	// 请求产生turtle2
	ros::service::waitForService("/spawn");
	ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");
	turtlesim::Spawn srv;
	add_turtle.call(srv);

	// 创建发布turtle2速度控制指令的发布者
	ros::Publisher turtle_vel = node.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);

	// 创建tf的监听器
	tf::TransformListener listener;

	ros::Rate rate(10.0);

	geometry_msgs::PointStamped center_obstacle_lidar, centor_obstacle_world;
	while (node.ok())
	{
		// 获取turtle1与turtle2坐标系之间的tf数据
		tf::StampedTransform transform;
		try
		{
			cout << "into listener while " << endl;
			center_obstacle_lidar.point.x = 1;
			center_obstacle_lidar.point.y = 1;
			center_obstacle_lidar.point.z = 0;
			center_obstacle_lidar.header.frame_id = "world";
			// center_obstacle_lidar.header.stamp = ros::Time().now();

			listener.waitForTransform("/turtle2", "/turtle1", ros::Time(0), ros::Duration(3.0));
			listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), transform);		  //坐标系间关系
			listener.transformPoint("turtle1", center_obstacle_lidar, centor_obstacle_world); //某个点在不同坐标系下的坐标
			cout << "world  : " << center_obstacle_lidar.point.x << ", " << center_obstacle_lidar.point.y << endl;
			cout << "turtle1: " << centor_obstacle_world.point.x << ", " << centor_obstacle_world.point.y << endl;
		}
		catch (tf::TransformException &ex)
		{
			ROS_ERROR("%s", ex.what());
			ros::Duration(1.0).sleep();
			continue;
		}

		// 根据turtle1与turtle2坐标系之间的位置关系，发布turtle2的速度控制指令
		geometry_msgs::Twist vel_msg;
		vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(),
										transform.getOrigin().x());
		vel_msg.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
									  pow(transform.getOrigin().y(), 2));
		turtle_vel.publish(vel_msg);

		rate.sleep();
	}
	return 0;
};
