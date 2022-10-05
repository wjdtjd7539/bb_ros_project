#include"ros/ros.h"
#include"yh_check/YhCheck.h"

bool distance=true;//둘다전역변수
bool camera=true;

void distanceCallback(const yh_check::YhCheck::ConstPtr& msg)
{
    distance=msg->data;//bool형데이터를 디스턴스에넣고
    if(distance && camera)//둘다트루면출력
    {
        ROS_INFO("OK");
    }

}

void cameraCallback(const yh_check::YhCheck::ConstPtr& msg)
{
    camera=msg->data;
    if(distance && camera)
    {
        ROS_INFO("OK");
    }
}


int main(int argc,char**argv)

{
    ros::init(argc,argv,"yh_check");
    ros::NodeHandle nh;

    ros::Subscriber sub_distance=nh.subscribe("check_distance",10,distanceCallback);

    ros::Subscriber sub_camera=nh.subscribe("check_camera",10,cameraCallback);
    //노드 두개를선언 second_sub.

    
    ros::spin();//콜백함수를기다린다(대기)

    

    return 0;
}   
