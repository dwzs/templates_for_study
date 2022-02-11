#include <ros/ros.h>
#include <std_msgs/Bool.h>

void tempCallback(const std_msgs::BoolConstPtr& msg)
{
    int num = 1;
    ros::Rate loop_rate(10);
    while (ros::ok() && num)
    {
        ROS_INFO_STREAM("temp call back, num->");
        num--;
        loop_rate.sleep();
    }
}

void longCallback(const std_msgs::BoolConstPtr& msg)
{
    int num = 10;
    ros::Rate loop_rate(10);
    while (ros::ok() && num)
    {
        ROS_INFO_STREAM("long call back, num->"<<num);
        num--;
        loop_rate.sleep();
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_node");

    ros::NodeHandle nh;
    ros::Subscriber tempSub = nh.subscribe<std_msgs::Bool>("temp", 1, tempCallback);
    ros::Subscriber longSub = nh.subscribe<std_msgs::Bool>("long", 1, longCallback);

    ros::MultiThreadedSpinner spinner(3);//三个线程订阅
    spinner.spin();

    return 0;
}
