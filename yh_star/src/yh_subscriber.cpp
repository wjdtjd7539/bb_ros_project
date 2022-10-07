#include "ros/ros.h"
#include "yh_star/mymymsg.h"

void msgCallback(const yh_star::mymymsg::ConstPtr& msg)//int(나머지) a(msg)와같다
{   
   int n=msg->data;
   for(int i=0;i<n/2; i++)
   {
    for(int j=0;j<i+1; j++)
    {
        printf("*");
    }
    printf("\n");

    //n/2까지 증가
    //그다음부터감소
   }
   for(int i=n/2;i<n;i++)
   {
    for(int j=n;j<i;j--)
    {
        printf("*");
    }
    printf("\n");


   }
   // ROS_INFO("receive msg:%d",msg->stamp.sec);
   // ROS_INFO("receive msg:%d",msg->stamp.nsec);
   // ROS_INFO("receive msg:%d",msg->data);
}

int main(int argc,char**argv)
{
    ros::init(argc,argv,"yh_subscriber");//노드이름초기화
    
    ros::NodeHandle nh;//노드핸들선언
    //서브스크라이버선언
    //패키지(std_msgs)의메시지(string)을이용한 서브스크라이버(sub)를선언한다
    //토픽은(sound)이며 서브스크라이버큐(queue)사이즈를 30으로설정한다
    //콜벡함수는(msgcallback)이다

    ros::Subscriber sub=nh.subscribe("sound",30,msgCallback);
    //콜벡함수호출을위한함수,메시지가수신되기를대기
    //수신되었을경우 콜백함수를호출한다

    ros::spin();

    return 0;
}