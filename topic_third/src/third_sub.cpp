#include "ros/ros.h"//ros헤더파일
#include "std_msgs/Int64.h"//std_msgs패키지의 string메시지해서

void msgCallback(const std_msgs::Int64::ConstPtr& msg)//int(나머지) a(msg)와같다
{
    ROS_INFO("count: %ld",msg->data);//*msg_data와같다

    
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"second_sub");//노드이름초기화
    ros::NodeHandle nh;//노드핸들선언
    //서브스크라이버선언
    //패키지(std_msgs)의메시지(STring)을이용한 서브스크라버(sub)를선언한다.
    //토픽은(my_count)이며 서브스크라이버큐(queue)사이즈를 100으로설정한다.
    //콜벡함수는 (msgCallback)이다ㅣ

    ros::Subscriber sub=nh.subscribe("mymy_count",100,msgCallback);
    //콜벡함수호출을위한함수,메시지가수신되기를 대기
    //수신되었을경우 콜백함수를 호출한다

    ros::spin();


    return 0;
}

