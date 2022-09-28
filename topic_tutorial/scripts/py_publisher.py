#!/usr/bin/python
#-*- coding: utf-8 -*-
import rospy
from std_msgs.msg import String

def talker():
    pub=rospy.Publisher("my_topic", String, queue_size=100)
    rospy.init_node("py_publisher")
    loop_rate=rospy.Rate(10)
    

    msg =String()
    msg.data="Bye"

    while not rospy.is_shutdown():#켜져있는동안무한반복
        pub.publish(msg)
        loop_rate.sleep()


if __name__=="__main__":#프라이빗변수 name일때만실행하겠다
    try:
        talker()
    except rospy.ROSInterruptException:
        pass    







