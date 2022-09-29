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
    