#!/usr/bin/python
#-*- coding:utf-8-*-

import rospy
from std_msgs.msg import Int32


def my_counter():
    rospy.init_node("py_second_pub")#노드이름초기화
    pub= rospy.Publisher("my_count", Int32,que_size=100)
    #펍선언 패키지(std_msg)의메시지파일(string)을이용한퍼블리셔 펍을만든다.
    #토픽은 my_count이며 퍼블리셔큐(queue)사이즈는(100)이다
    
    loop_rate=rospy.Rate(20)#루프주기를20으로설정한다

    msg=Int32()
    msg.data=0#메시지data에 0을넣는다

    while not rospy.is_shutdown():
        pub.publish(msg)#pub이 msg를 퍼블리시한다.
        loop_rate.sleep() #hz에맞게 쉬는동작
        msg.data+=1#1씩더한다

if  __name__ =="__main__":
    try:
        my_counter()
    except rospy.ROSInterruptException:
        pass




