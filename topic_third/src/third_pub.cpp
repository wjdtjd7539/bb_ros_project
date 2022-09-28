#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"second_pub");
    ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<std_msgs::Int64>("mymy_count",100);

    ros::Rate loop_rate(4);

    std_msgs::Int64 msg;
    msg.data=0;

    while(ros::ok())
    {   
        
        pub.publish(msg);
        loop_rate.sleep();
        msg.data++;

        if(msg.data==100){
        msg.data=0;    
        }
      
        
    }

    return 0;
}

