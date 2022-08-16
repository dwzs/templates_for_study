#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

class Topic_SubPub
{
public:
    Topic_SubPub(std::string sub_name);

private:
    void subCallback(const nav_msgs::Odometry::ConstPtr &msgs);

    ros::NodeHandle nh_;

    ros::Subscriber sub;
    ros::Publisher pub;
};

Topic_SubPub::Topic_SubPub(std::string sub_name)
{
    sub = nh_.subscribe<nav_msgs::Odometry>(sub_name, 10, &Topic_SubPub::subCallback, this);
    pub = nh_.advertise<nav_msgs::Odometry>("pub_name", 1);
}

void Topic_SubPub::subCallback(const nav_msgs::Odometry::ConstPtr &msgs)
{
    //to do sths
    // pub.publish(...);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "nodeSubPub");

    Topic_SubPub subPub("/subName");

    ros::spin();
    return 0;
}