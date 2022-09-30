#include"ros/ros.h"
#include"service_tutorial/AddTwoInts.h"//서비스헤더파일
                                        //빌드시 생성
//서비스 요청이 있을경우 실행되는 콜백함수
//서비스 요청은 req, 서비스 응답은 res로 설정
bool add(service_tutorial::AddTwoInts::Request& req,
         service_tutorial::AddTwoInts::Response& res)//위아래 위는리퀘스트 아래는 리스폰스
{
    res.result=req.a+req.b;
    ROS_INFO("request: a=%d,b=%d",req.a,req.b);
    ROS_INFO("response: result=%d");//출력
    return true;// 응답을잘했다

}   

int main(int argc,char** argv)

{
    ros::init(argc,argv,"my_server");
    ros::NodeHandle nh;

    //서비스 서버(my_server)를 선언한다.
    //서비스 이름은 (add_two_ints)이고 , 요청이 왔을때(add)를 실행한다.
    //(service_tutorial)패키지의 (AddTwoInts)서비스 파일을 이용한다.two_ints
    ros::ServiceServer my_server=nh.advertiseService("add_",add);

    ROS_INFO("Service Server Ready.");

    ros::spin();

    return 0;
}


