/*

接收话题后同时发布

*/

#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

void subCallback(const nav_msgs::Odometry::ConstPtr &msg, ros::Publisher *pub)
{
    //to do sths
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rpylistener");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<nav_msgs::Odometry>("pub_name", 1);
    ros::Subscriber sub = n.subscribe<nav_msgs::Odometry>("sub_name", 0, boost::bind(&subCallback, _1, &pub));

    ros::spin();
    return 0;
}
