#include "ros/ros.h"//ros헤더파일
#include "std_msgs/Int32.h"//string 메시지헤더파일

int main(int argc,char** argv)
{
    ros::init(argc,argv, "second_pub");//노드이름초기화
    ros::NodeHandle nh;//ros시스템과 통신을위한노드핸들선언
    //퍼블리셔선언
    //패키지(std_msg)의메시지파일(string)을 이용한 퍼블리셔(pub)를 만든다.
    //토픽은(my_topic)이며,퍼블리셔큐(queue)사이즈는(100)이다.
    ros::Publisher pub=nh.advertise<std_msgs::Int32>("my_count",100);

    ros::Rate loop_rate(2);//루프주기를 2hz로설정한다.
    
    std_msgs::Int32 msg;
    msg.data=0;//msg의 data에 0을넣는다.

    while(ros::ok())
    {
        pub.publish(msg);//pub이 msg를 퍼블리시한다.
        loop_rate.sleep();//위에서 정한주기에따라 sleep한다
        msg.data++;//1씩더한다
    }


    

    return 0;

}


