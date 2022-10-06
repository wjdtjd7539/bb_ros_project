#include"ros/ros.h"
#include"std_msgs/Float32.h"

void msgCallback(const std_msgs::Float32::ConstPtr& msg)
{
    ROS_INFO("%f",msg->data);
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"yh_connect_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub_distance=nh.subscribe("yh_connect_float",10,msgCallback);
    //서브스크라이버선언
    //패키지(std_msgs)의메시지(String2)을이용한 서브스크라버(sub)를선언한다.
    //토픽은(yh_connect_float)이며 서브스크라이버큐(queue)사이즈를 10으로설정한다.
    //콜벡함수는 (msgCallback)이다ㅣ

    ros::spin();

    return 0;

}

