#include "ros/ros.h"
#include "std_srvs/Empty.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv, "turtle_clear");
    ros::NodeHandle nh;

    ros::ServiceClient clear_client=nh.serviceClient<std_srvs::Empty>("clear");
    //앞이자료형 뒤가노드이름 클리어는서비스이름

    std_srvs::Empty srv;

    if(clear_client.call(srv))
    {

        ROS_INFO("Clear");

    }
    else
    {
        ROS_ERROR("Failed");
        return 1;
    }

    return 0;

}

