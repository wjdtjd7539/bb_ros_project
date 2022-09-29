#!/usr/bin/python
#-*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String #std_msg패키지안에 string메시지를 헤더

def talker():
    pub=rospy.Publisher("my_topic", String, queue_size=100)
    rospy.init_node("py_publisher")#py publisher 초기화
    loop_rate=rospy.Rate(10)#루프주기설정
    

    msg =String() #msg에 msg타입설정
    msg.data="Bye"#data에 bye를대입

    while not rospy.is_shutdown():#켜져있는동안무한반복
        pub.publish(msg) #pub안에 퍼블리시를 메시지를넣어서 수행
        loop_rate.sleep()#위에지정한rate주기로 쉰다


if __name__=="__main__":#프라이빗변수 name일때만실행하겠다
    try:
        talker()
    except rospy.ROSInterruptException:#오류  종료로 인해 중단된 작업에 대한 예외입니다.
        pass    







