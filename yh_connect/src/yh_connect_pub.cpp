#include "ros/ros.h"
#include"std_msgs/Int32.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"yh_connect_pub");//노드이름초기화
    ros::NodeHandle nh;//ros시스템과 통신을위한노드핸들선언
    //퍼블리셔선언
    //패키지(std_msg)의메시지파일(string)을 이용한 퍼블리셔 (pub)룰만든다.
    //토픽은(yh_connect_int)이며,퍼블리서큐(queue)사이즈는(10)이다.
    ros::Publisher pub =nh.advertise<std_msgs::Int32>("yh_connect_int",10);

    ros::Rate loop_rate(4);

    std_msgs::Int32 msg;
    //std_msgs 받을 인자가 Int32로 필요한다 위에int32와다르다(통신을하기위함)

    int cnt=0;

    while(ros::ok())
    {
        msg.data++;
        
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}