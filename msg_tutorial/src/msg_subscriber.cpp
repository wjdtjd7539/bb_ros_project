#include "ros/ros.h"
#include "msg_tutorial/Mymsg.h" //Mymsg 메시지헤더파일
                                //빌드시 자동생성

//void msgCallback(const std_msgs::Int64::Constptr& msg)
void msgCallback(const msg_tutorial::Mymsg::ConstPtr& msg)//퍼블리셔한테받으면진행되는함수
{
    ROS_INFO("receive msg:%d",msg->stamp.sec);
    ROS_INFO("receive msg:%d",msg->stamp.nsec);
    ROS_INFO("receive msg:%d",msg->data);

}

int main(int argc,char**argv)
{
    ros::init(argc,argv,"msg_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe("burger",30,msgCallback);

    ros::spin();//콜백기다리는함수


    return 0;
}