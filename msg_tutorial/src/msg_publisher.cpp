#include "ros/ros.h"//ros 헤더파일
#include "msg_tutorial/Mymsg.h"//Mymsg 메시지헤더파일
                                //빌드시자동생성


int main(int argc,char** argv)
{
    ros::init(argc,argv,"msg_publisher");//노드이름초기화
    ros::NodeHandle nh;//ros시스템과 통신을위한노드핸들선언
    //퍼블리셔선언
    //패키지(msg_tutorial)의메시지파일(Mymsg)을 이용한 퍼블리셔 pub를 만든다.
    //토픽은(burger)이며,퍼블리셔큐(queue)사이즈는(100)이다.

    ros::Publisher pub =nh.advertise<msg_tutorial::Mymsg>("burger",20);//advertise함수를이용해 퍼블리시하고 메시지형태는Mymsg 토픽이름버거 큐사이즈20이다
    ros::Rate loop_rate(2);

    msg_tutorial::Mymsg msg;
    int cnt=0;




    while(ros::ok())
    {
        /*msg{
            time stamp
            int32 data

        }*/
        
        msg.stamp=ros::Time::now();//현재시간을msg의stamp에담는다.
        msg.data=cnt;//cnt 변수의값을msg의data에담는다
        ROS_INFO("send msg:%d",msg.stamp.sec);//stamp.sec를출력한다
        ROS_INFO("send msg:%d",msg.stamp.nsec);//stamp.nsec를출력한다
        ROS_INFO("send msg:%d",msg.data);//data를출력한다
        pub.publish(msg);
        cnt++;
        loop_rate.sleep();

    
    }




    return 0;
}

