#!/usr/bin/python3
#-*- coding:utf-8--*-

import rospy
from yh_dual.msg import Mymsg

def my_timer():
    rospy.init_node("yh_dual")
    pub=rospy.Publisher("my_timeint",Mymsg,queue_size=100)

    loop_rate=rospy.Rate(8)

    msg=Mymsg()
    cnt=0
    msg.data=0

    while not rospy.is_shutdown():
        msg.stamp=rospy.Time.now()
        msg.data=cnt
        rospy.loginfo("send msg:%d",msg.stamp.secs)
        rospy.loginfo("send msg:%d",msg.stamp.nsecs)
        rospy.loginfo("send msg:%d",msg.data)

        pub.publish(msg)
        cnt+=1
        loop_rate.sleep()
        msg.data+=1

if __name__=="__main__":
    try:
        my_timer()
    except rospy.ROSInterruptException:
        pass