
#include <ros/ros.h>
#include <std_msgs/builtin_int32.h>
#include <std_msgs/ByteMultiArray.h>
#include "../proto/person.pb.h"

using namespace std;

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "person_publisher");
    // 创建节点句柄
    ros::NodeHandle n;
    // 创建一个Publisher，发布名为/person_info的topic，消息类型为learning_topic::Person，队列长度10
    ros::Publisher person_info_pub = n.advertise<std_msgs::ByteMultiArray>("/person_info", 10);
    // 设置循环的频率
    ros::Rate loop_rate(1);

    ///////////////////////////////////////////
    char buf[1024];
    int len;

    GOOGLE_PROTOBUF_VERIFY_VERSION;

    Person obj;
    obj.set_name("gongluck");
    obj.set_id(1);
    *obj.mutable_email() = "http://blog.csdn.net/gongluck93";
    len = obj.ByteSize();
    cout << "len = " << len << endl;
    obj.SerializeToArray(buf, len);
    ////////////////////////////////////////////

    std_msgs::ByteMultiArray data;
    data.data.resize(len);
    // obj.SerializeToArray(data.data, len); //出错，应该是地址搞错，此地址非需要的地址
    obj.SerializeToArray(&data.data[0], len);

    // Person obj2;
    // obj2.ParseFromArray(&data.data, len);
    // cout << "name = " << obj2.name() << endl;
    // cout << "id = " << obj2.id() << endl;
    // cout << "email = " << obj2.email() << endl;

    int i = 0;
    while (ros::ok())
    {
        ROS_INFO("data.size() is:%d", data.data.size());
        // ROS_INFO("sizeof(data) is:%d", sizeof(data.data));
        // ROS_INFO("sizeof(buf) is:%d", sizeof(buf));

        // 发布消息
        person_info_pub.publish<std_msgs::ByteMultiArray>(data);

        // 按照循环频率延时
        loop_rate.sleep();
        i++;
        ROS_INFO("i is:%d", i);
    }

    return 0;
}