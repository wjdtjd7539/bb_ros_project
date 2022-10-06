# bb_ros_project
My first ros study


## 2022-09-27 start
##dfa

## 2022-09-27 start
tutorial pakage에 파이썬스크립트추가
publisher,subscriber py 노드생성
빌드실행
'''bash
    rosrun<패키지이름><노드이름>


### catkin_create_pkg
    현재위치한작업공간에 패키지를 생성한다
    catkin_create_pkg 패키지이름 의존성

'''bash
```bash
        catkin_create_pkg<패키지이름><의존성1>
        <의존성2>...
```
```bash
    catkin_create_pkg topic_tutorial roscpp
    rospy std_msgs
```
    topic_second 패키지 생성
    second_pub,second_sub,py_second_pub.py,second_sub.py
    노드생성

    과제1
    
####

2022년 9월29일
[msg_tutorial](./msg_tutorial)
    msg_tutorial 패키지 생성
    msg 디렉토리에 Mymsg.msg 생성
    msg publisher,msg subscriber,py_msg_pub.py,py_msg_sub.py 노드생성
    빌드
    실행

[service_tutorial](./service_tutorial)
-service_tutorial생성
-py_client.py,py_server.py생성
-my_client.cpp,my_server.cpp생성
####

2022년 9월30일
[과제 2 yh_star](./yh_star)
for문활용해서 별찍기
    yh_star 패키지 생성
    yh_star_pub,yh_star_sub,yh_star_pub.py,
    yh_star_sub.py 노드생성
    빌드
    실행

[과제3 yh_service](./yh_service)
    yh_service 패키지 생성
    yh_server,yh_client,yh_server.py,yh_client.py
    노드생성
    빌드
    실행

## 2022년10월4일
파라미터서버 로스마스터에서실행되고 변수들을담고있는서버이다
ros::param() ros::getparam(),rospy.set_param(),rospy.get_param()등의 함수로사용
cmmand line에서 rosparam으로 사용가능
rosparam list
파라미터서버의모든파라미터를출력
## 2022년 10월5일
### [과제6 yh_check](./yh_check)
    [과제6](./yh_check/과제6.pdf)
    yh_check 패키지 생성
    yh_check_distance, yh_check_camera,yh_check_sub,
    yh_check_distance.py,yh_check_camera.py,yh_check_sub.py노드생성
        빌드
        실행
        python클래스로작성

### [과제7 yh_connect](./yh_connect)
-[과제7](./yh_conncect/과제7.pdf)
    yh_connect 패키지 생성
    yh_connect_pub,yh_connect_sub,yh_connect_sub_pub,
    yh_connect_pub.py,yh_connect_sub.py,yh_connect_sub_pub.py노드생성
        빌드
        실행
        python클래스로작성

### 2022년 10월 6일
### [yh_turtle](./yh_turtle)
-yh_turtle패키지생성
-turtle_keyboard,clear,patrol.cpp 
-turtle_clear,keyboard_claear,keboard.py노드생성
### [teleop_twist_keyboard 패키지]
키보드입렵을받아/cmd vel 토픽의 geometry_msgs/Twist메시지로 publish 하는 노드

$sudo apt install ros-melodic-teleop-twist-keyboard
실행

$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py


#### [roslaunch](#roslaunch)
    roscore와 launch 파일에 있는 노드들을 실행시키는명령
    launch파일을 '패키지 디렉토리 /launch'에 위치에만든다
    roslaunch 명령

$ roslaunch<패키지이름><런치파일이름>

launch 파일은<launch></launch>태그 사이에 내용을 입력한다.
node 태그는 패키지이름,노드타입, 노드이름을 입력한다.
param태그는 파라미터 이름,값,타입을 입력한다.
