#!/usr/bin/python3
#-*- coding:utf-8-*-

import rospy
from yh_dual.msg import Mymsg

def msgCallback(msg):

    rospy.loginfo(" msg: %d",msg.data)
   

def my_int():
    rospy.init_node("yh_dual_int")
    rospy.Subscriber("my_timeint",Mymsg,msgCallback, queue_size=100)

    rospy.spin()


if __name__=="__main__":
    my_int()
