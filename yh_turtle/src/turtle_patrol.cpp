#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char** argv)
{
    ros::init(argc,argv, "turtle_patrol");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);
    
    ros::Rate loop_rate(100);

    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;
    msg.linear.y = 1.0;
    //msg.linear.z = 0.0;
    

    while (ros::ok())
    {
        pub.publish(msg);
        msg.linear.x *= -1;
        msg.linear.y *= -1;
        //msg.linear.z *= -1;


        loop_rate.sleep();
    }


    return 0;
}