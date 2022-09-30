#include "ros/ros.h"//ros헤더파일
#include "yh_star/mymymsg.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"yh_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub =nh.advertise<yh_star::mymymsg>("sound",20);
    ros::Rate loop_rate(2);

    yh_star::mymymsg msg;
    int cnt=1;


    while(ros::ok())
    {
        msg.stamp=ros::Time::now();
        msg.data=cnt;
        
        pub.publish(msg);
        cnt++;
        loop_rate.sleep();
    }

    return 0;
}