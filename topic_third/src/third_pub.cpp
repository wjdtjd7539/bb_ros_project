#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"second_pub");//노드이름초기화
    ros::NodeHandle nh;//ros시스템과 통신을위한노드핸들선언
    //퍼블리셔선언
    //패키지(std_msg)의메시지파일(string)을 이용한 퍼블리셔 (pub)룰만든다.
    //토픽은(my_topic)이며,퍼블리서큐(queue)사이즈는(100)이다.
    ros::Publisher pub=nh.advertise<std_msgs::Int64>("mymy_count",100);

    ros::Rate loop_rate(4);//루프주기를 2hz로설정한다

    std_msgs::Int64 msg;
    msg.data=0;//msg의 data에 0을넣는다

    while(ros::ok())
    {   
        
        pub.publish(msg);//pub이 msg를퍼블리시한다
        loop_rate.sleep();//위에서 정한주기에따라 sleep한다
        msg.data++;//1씩더한다

        if(msg.data==100){
        msg.data=0;    
        }
      
        
    }

    return 0;
}

