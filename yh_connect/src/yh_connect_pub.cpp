#include "ros/ros.h"
#include"std_msgs/Int32.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"yh_connect_pub");
    ros::NodeHandle nh;

    ros::Publisher pub =nh.advertise<std_msgs::Int32>("yh_connect_int",10);

    ros::Rate loop_rate(4);

    std_msgs::Int32 msg;

    int cnt=0;

    while(ros::ok())
    {
        msg.data++;
        
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}