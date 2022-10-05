#include "ros/ros.h"//ros헤더파일
#include "yh_star/mymymsg.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"yh_publisher");//노드이름초기화
    ros::NodeHandle nh;//ros시스템과 통신을위한노드핸들선언
    //퍼블리셔선언
    //패키지(std_msg)의메시지파일(string)을이용한 퍼블리셔(pub)을만든다
    //토픽은(sound)이며,퍼블리서큐사이즈는20이다

    ros::Publisher pub =nh.advertise<yh_star::mymymsg>("sound",20);
    ros::Rate loop_rate(2);

    yh_star::mymymsg msg;
    int cnt=1;


    while(ros::ok())
    {
        msg.stamp=ros::Time::now();//현재시간을 메시지스탬프에대입한다
        msg.data=cnt;//메시지데이타에 cnt를대입한다
        
        pub.publish(msg);
        cnt++;//cnt는1씩증가한다
        loop_rate.sleep();//위에서정한주기에따라sleep한다
    }

    return 0;
}