#!/usr/bin/python
#-*- coding:utf-8-*-

import rospy#Ros헤더파일
from std_msgs.msg import Int32#int(나머지) a(msg)와 같다


def msgCallback(msg):  
    rospy.loginfo("msg: %d ,msg.data")

def my_listener():
    rospy.init_node("py_second_sub")
    rospy.Subscriber("my_count",Int32,msgCallback, queue_size=100)

    rospy.spin()


if __name__=="__main__":
    my_listener()
