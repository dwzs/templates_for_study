/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * 该例程将订阅lgsvl发布的里程计话题（/odom）,然后提取x,y,z,yaw,v信息，并保存成文件
 */

#include <ros/ros.h>
#include <iostream>
#include <fstream> // ifstream, ofstream
#include <string>
#include "visualization_msgs/Marker.h"

using namespace std;

string sFilename = "/home/wsy/catkin_worspace1/resources/lgsvl_cube/cube.path";

void readTraj(visualization_msgs::Marker &refTraj)
{
    ifstream fileSource(sFilename);
    if (!fileSource)
    {
        cerr << "can not open " << sFilename << endl;
        exit(1);
    }
    else
    {
        string buffer;
        geometry_msgs::Point p;
        while (getline(fileSource, buffer))
        {
            // cout << buffer << endl;
            stringstream buffer1(buffer);
            string token;
            int i = 0;
            while (getline(buffer1, token, ','))
            {
                // cout << token << endl;
                if (i % 15 == 5)
                {
                    p.x = stof(token);
                }
                if (i % 15 == 6)
                {
                    p.y = stof(token);
                }
                if (i % 15 == 7)
                {
                    p.z = stof(token);
                    // p.z = 0;
                }
                refTraj.points.push_back(p);
                i++;

                // cout << "x:" << p.x << "  "
                //      << "y:" << p.y << "  "
                //      << "z:" << p.z << endl;
            }
        }
    }
    // fileSource.close();
}

void fillMarker(visualization_msgs::Marker &refTraj)
{
    refTraj.action = refTraj.ADD;
    refTraj.header.stamp = ros::Time::now();
    refTraj.header.frame_id = "world";
    refTraj.lifetime = ros::Duration();
    refTraj.ns = "reference_path";
    refTraj.id = 0;
    refTraj.type = visualization_msgs::Marker::POINTS;

    refTraj.pose.orientation.w = 1.0;
    refTraj.scale.x = 0.2;
    refTraj.scale.y = 0.2;
    refTraj.scale.z = 0.2;
    refTraj.color.r = 0.0 / 255.0;
    refTraj.color.g = 255.0 / 255.0;
    refTraj.color.b = 0.0 / 255.0;
    refTraj.color.a = 1.0;
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "track_display");
    // 创建节点句柄
    ros::NodeHandle n;
    // 创建一个Subscriber，订阅名为/turtle1/pose的topic，注册回调函数poseCallback
    ros::Publisher trajectory_pub = n.advertise<visualization_msgs::Marker>("/ref_traj", 1000);

    visualization_msgs::Marker refTraj_msg;

    fillMarker(refTraj_msg);
    readTraj(refTraj_msg);

    // 设置循环的频率
    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        // 发布消息
        trajectory_pub.publish(refTraj_msg);

        // 按照循环频率延时
        loop_rate.sleep();
    }

    // 循环等待回调函数
    ros::spin();

    return 0;
}
