#include "ros/ros.h"//ros헤더파일
#include "std_msgs/String.h" //string 메시지헤더파일

int main(int argc,char** argv)
{
    ros::init(argc,argv,"my_publisher");//노드 이름 초기화
    ros::NodeHandle nh;//ros시스템과 통신을위한노드핸들선언
    //퍼블리셔선언
    //패키지 (std_msgs)의 메시지파일(string)을 이용한 퍼블리셔(pub)를 만든다.
    //토픽은(my_topic)이며,퍼블리셔큐(queue)사이즈는(100)이다.
    ros::Publisher pub =nh.advertise<std_msgs::String>("my_topic",100);//nh.advertise는퍼블리셔만드는함수이다

    ros::Rate loop_rate(10);//루프주기를 10hz로 설정한다.

    std_msgs::String msg;
    msg.data="Hello";//msg의 data에 Hello를 넣는다.

    while (ros::ok())
    {
        pub.publish(msg);//pub이 msg를 퍼블리시한다.
        loop_rate.sleep();//위에서 정한주기에따라sleep한다.

    }






    return 0;
}


