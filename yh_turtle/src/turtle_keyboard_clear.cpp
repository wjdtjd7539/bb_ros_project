#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_srvs/Empty.h"

ros::Publisher pub;
//전역변수
ros::ServiceClient clear_client;
//전역변수
std_srvs::Empty srv;

void msgCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
    pub.publish(*msg);
    if(msg->linear.z>0.0)
    {

        if(clear_client.call(srv))//client가서비스통신한것이다
        {
            ROS_INFO("CLEAR");//통신되었을때
        }
        else
        {
            ROS_ERROR("FAILED");//통신안되었을때
        }
    }

}

int main(int argc,char** argv)
{
    ros::init(argc,argv, "turtle_keyboard_clear");
    ros::NodeHandle nh;

    pub=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",100);
    clear_client=nh.serviceClient<std_srvs::Empty>("clear");
    ros::Subscriber sub =nh.subscribe("cmd_vel",100,msgCallback);

    ros::spin();

    return 0;

}