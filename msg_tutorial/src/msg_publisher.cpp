#include "ros/ros.h"
#include "msg_tutorial/Mymsg.h"//Mymsg 메시지헤더파일
                                //빌드시자동생성


int main(int argc,char** argv)
{
    ros::init(argc,argv,"msg_publisher");
    ros::NodeHandle nh;

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

