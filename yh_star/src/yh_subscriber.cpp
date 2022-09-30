#include "ros/ros.h"
#include "yh_star/mymymsg.h"

void msgCallback(const yh_star::mymymsg::ConstPtr& msg)
{   
   int n=msg->data;
   for(int i=0;i<n/2; i++)
   {
    for(int j=0;j<i+1; j++)
    {
        printf("*");
    }
    printf("\n");

    //n/2까지 증가
    //그다음부터감소
   }
   for(int i=n/2;i<n;i++)
   {
    for(int j=n;j<i;j--)
    {
        printf("*");
    }
    printf("\n");


   }
   // ROS_INFO("receive msg:%d",msg->stamp.sec);
   // ROS_INFO("receive msg:%d",msg->stamp.nsec);
   // ROS_INFO("receive msg:%d",msg->data);
}

int main(int argc,char**argv)
{
    ros::init(argc,argv,"yh_subscriber");
    
    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe("sound",30,msgCallback);

    ros::spin();

    return 0;
}