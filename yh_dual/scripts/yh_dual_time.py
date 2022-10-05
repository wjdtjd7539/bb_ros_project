#!/usr/bin/python3
#-*- coding:utf-8-*-

import rospy
from yh_dual.msg import Mymsg

def msgCallback(msg):
    rospy.loginfo("receive msg: %d",msg.stamp.secs)
    rospy.loginfo("receive msg: %d",msg.stamp.nsecs)
    rospy.loginfo("receive msg: %d",msg.data)

def my_time():
    rospy.init_node("yh_dual_int")
    rospy.Subscriber("my_timeint",Mymsg,msgCallback, queue_size=100)

    rospy.spin()


if __name__=="__main__":
    my_time()