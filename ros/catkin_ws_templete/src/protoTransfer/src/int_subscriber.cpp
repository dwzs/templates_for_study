/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * 该例程将订阅/person_info话题，自定义消息类型learning_topic::Person
 */

#include <ros/ros.h>
#include <std_msgs/builtin_int32.h>
#include <std_msgs/ByteMultiArray.h>
#include "../proto/person.pb.h"

using namespace std;
// // 接收到订阅的消息后，会进入消息回调函数
// void personInfoCallback(const std_msgs::Int32 &msg)
// {
//     // 将接收到的消息打印出来
//     ROS_INFO("received i is:%d", msg);
// }
// 接收到订阅的消息后，会进入消息回调函数
void personInfoCallback(const std_msgs::ByteMultiArray &data)
{
    Person obj2;
    obj2.ParseFromArray(&data.data[0], data.data.size());
    cout << "name = " << obj2.name() << endl;
    cout << "id = " << obj2.id() << endl;
    cout << "email = " << obj2.email() << endl;
}

int main(int argc, char **argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "person_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/person_info的topic，注册回调函数personInfoCallback
    ros::Subscriber person_info_sub = n.subscribe("/person_info", 10, personInfoCallback);

    // 循环等待回调函数
    ros::spin();

    return 0;
}
