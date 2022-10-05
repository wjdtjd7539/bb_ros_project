#include "ros/ros.h"
#include "param_tutorial/Calculate.h"

#define PLUS 1//PLUS를 1로바꿔서 저장한다 PLUS는 1로바뀐다
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4

int my_operator=PLUS;

bool calculation(param_tutorial::Calculate::Request& req,
                param_tutorial::Calculate::Response& res)
{
    switch (my_operator)
    {
        case PLUS:
            res.result=req.a+req.b;
            break;
        case MINUS:
            res.result=req.a-req.b;
            break;
        case MULTIPLICATION:
            res.result=req.a*req.b;
            break;
            
        case DIVISION:
            res.result=req.a/req.b;
            break;
        default:
            res.result=req.a+req.b;
            break;
    }
   ROS_INFO("a: %d,b: %d,result: %d",req.a,req.b,res.result);
   return true;

} 

int main(int argc,char** argv)
{   
    ros::init(argc,argv,"calculate_server");
    ros::NodeHandle nh;

    nh.setParam("calculation_method",PLUS);//method에 plus 파라미터 초기설정

    ros::ServiceServer calculate_server=nh.advertiseService("calculate",calculation);

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        nh.getParam("calculation_method",my_operator);//파라미터서버에있는 메소드를 my_operator 에가져와서할당하겠다
        ros::spinOnce();//대기하다가 콜백호출을한번만하고 프로그램이꺼진다 콜벡사이에서 어떤기능을하고싶을때주로쓰인다.
        loop_rate.sleep();

    }

    return 0;




    return 0;
}

