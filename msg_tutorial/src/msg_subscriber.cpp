#include "ros/ros.h"//Ros 헤더파일
#include "msg_tutorial/Mymsg.h" //Mymsg 메시지헤더파일
                                //빌드시 자동생성

//void msgCallback(const std_msgs::Int64::Constptr& msg)
void msgCallback(const msg_tutorial::Mymsg::ConstPtr& msg)//퍼블리셔한테받으면진행되는함수
{
    ROS_INFO("receive msg:%d",msg->stamp.sec);//stamp.sec을출력한다
    ROS_INFO("receive msg:%d",msg->stamp.nsec);//stamp.nsec을출력한다
    ROS_INFO("receive msg:%d",msg->data);//data를 출력한다

}

int main(int argc,char**argv)
{
    ros::init(argc,argv,"msg_subscriber");//노드이름초기화

    ros::NodeHandle nh;//노드핸들선언

    ros::Subscriber sub=nh.subscribe("burger",30,msgCallback);
    //서브스크라이버선언
    //패키지(msg_tutorial)의메시지(Mymsg)를이용한 서브스크라이버(sub)를 선언한다.
    //토픽은(burger)이며,서브스카이버큐(queue)사이즈를 30으로 설정한다
    //콜벡함수는 (msgCallback)이다.
    ros::spin();//콜백기다리는함수
    //콜백함수호출을위한함수,메시지가 수신되기들 대기
    //수신되었을 경우 콜백함수를 호출한다
    //spin은대기함수이다 무한반복 콜벡함수를 기다린다 메시지가오면 콜백메세지가 실행된다
    return 0;
}