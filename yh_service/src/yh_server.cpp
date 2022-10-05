#include"ros/ros.h"
#include"yh_service/YhSrv.h"

bool multiply(yh_service::YhSrv::Request& req,
              yh_service::YhSrv::Response& res)
              //bool은true와false만받을수있는1true 0false형태이다
{
    res.result=req.a*req.b;
    ROS_INFO("a:%d,b:%d,result=%d", req.a, req.b,res.result);
    return true;
}

int main(int argc,char**argv)

{
    ros::init(argc,argv,"yh_server");
    ros::NodeHandle nh;

    ros::ServiceServer yh_server=nh.advertiseService("multiply",multiply);
    //메시지유형을저장한다
    ros::spin();//콜백함수를기다린다(대기)

    return 0;
}   
//topic이란 노드들 간에 통신을 할 수 있는 채널이다. 두 프로그램 간에 어떤 통신이 발생하고, 어떤 메시지를 주고 받게 되는데 이 경로를 토픽이라고 한다. 
//- 메세지는 Topic이 데이터나 정보를 주고 받을 때 사용하는 포맷이다