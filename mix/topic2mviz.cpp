#include <ros/ros.h>
#include "/opt/ros/melodic/include/lgsvl_msgs/CanBusData.h"
#include <publisher.h>

using namespace std;
using namespace mdc::visual;

Publisher g_canMsgPub = Publisher::Advertise<VehicleStatus>(ara::core::String("TopicVehicleInfo"));

void convertTopic2Mviz(const lgsvl_msgs::CanBusDataPtr& msg, VehicleStatus& vehicleStatus)
{
    vehicleStatus.steeringWheelAngle = -msg->steer_pct*39.4;
    vehicleStatus.vehicleSpeed = msg->speed_mps;
    vehicleStatus.throttle = msg->throttle_pct;
    vehicleStatus.brake = msg->brake_pct;
}

// 接收到订阅的消息后，会进入消息回调函数
void poseCallback(const lgsvl_msgs::CanBusDataPtr& msg)
{
    // 将接收到的消息打印出来
    // ROS_INFO("Turtle speed:%0.6f, steer:%0.6f", msg->speed_mps, msg->steer_pct);

    VehicleStatus vehicleStatus;
    //发送 mvizdata topic
    convertTopic2Mviz(msg, vehicleStatus);
    g_canMsgPub.Publish(vehicleStatus);

}

int main(int argc, char **argv)
{
    // 开启viz库功能，尝试连接服务端
    bool result = mdc::visual::Connect();
    if (result) {
        ROS_INFO("The MViz server address is parsed and the visualization client is created successfully.");
    } else {
        ROS_INFO("Failed to parse the MViz server address, or a visualization client has been created.");
        return 0;
    }

    // 初始化ROS节点
    ros::init(argc, argv, "svl_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/turtle1/pose的topic，注册回调函数poseCallback
    ros::Subscriber pose_sub = n.subscribe("/svl_canbus", 10, poseCallback);

    // 循环等待回调函数
    ros::spin();

    // 关闭viz-lib库功能，断开跟服务端的连接
    mdc::visual::Close();

    return 0;
}














