#include "ros/ros.h"
#include "std_msgs/Int32.h"

void msgCallback(const std_msgs::Int32::ConstPtr& msg)   //int(나머지) a(msg)와같다
{
    ROS_INFO("count: %d",msg->data);
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"second_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe("my_count",100,msgCallback);

    ros::spin();




    return 0;

}


