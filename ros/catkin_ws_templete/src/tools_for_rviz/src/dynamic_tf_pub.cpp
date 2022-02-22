

/**
 * 接收定位数据后根据定位数据转换成tf关系
 */

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

std::string turtle_name;

void poseCallback(const nav_msgs::OdometryPtr &msg)
{
	// 创建tf的广播器
	static tf::TransformBroadcaster br;

	// 初始化tf数据
	tf::Transform transform;
	transform.setOrigin(tf::Vector3(msg->pose.pose.position.x, msg->pose.pose.position.y, msg->pose.pose.position.z));

	tf::Quaternion q;
	q.setX(msg->pose.pose.orientation.x);
	q.setY(msg->pose.pose.orientation.y);
	q.setZ(msg->pose.pose.orientation.z);
	q.setW(msg->pose.pose.orientation.w);
	transform.setRotation(q);

	// 广播world与海龟坐标系之间的tf数据
	br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "f_origin", "f_base"));
}

int main(int argc, char **argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "dynamic_tf_pub");

	// 订阅海龟的位姿话题
	ros::NodeHandle node;
	ros::Subscriber sub = node.subscribe("/svl_odom", 10, &poseCallback);

	// 循环等待回调函数
	ros::spin();

	return 0;
};
