#include "ros/ros.h" // Ros 헤더파일
#include "std_msgs/String.h"//std_msgs 패키지의 String메시지 헤더


void msgCallback(const std_msgs::String::ConstPtr& msg)
{
 ROS_INFO("msg: %s",msg->data.c_str());//*msg_data와같다  
  
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"my_subscriber");// 노드이름초기화
    ros::NodeHandle nh;//노드핸들선언
    //서브스크라이버선언
    //패키지(std_msgs)의 메시지(string)를 이용한 서브스크라이버(sub)를 선언한다.
    //토픽은(my_topic)이며, 서브스크라이버큐(queue) 사이즈를 100으로 설정한다.
    //콜벡함수는 (msgCallback)이다.

    ros::Subscriber sub =nh.subscribe("my_topic",100,msgCallback);
    //콜백함수호출을위한함수,메시지가 수신되기를대기
    //수신되었을 경우 콜백함수를 홀출한다

    ros::spin();//spin 은대기하는함수이다 무한반복 콜벡함수를기다린다


    return 0;

}
