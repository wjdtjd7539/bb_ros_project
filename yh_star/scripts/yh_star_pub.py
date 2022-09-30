#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from yh_star.msg import mymymsg

def msg_talker():
    rospy.init_node("yh_star_pub")

    pub=rospy.Publisher("sound",mymymsg,queue_size=10)

    loop_rate=rospy.Rate(2)

    msg=mymymsg()
    cnt=0


    while not rospy.is_shutdown():
        msg.stamp=rospy.Time.now()
        msg.data=cnt
        rospy.loginfo("send msg:%d",msg.stamp.secs)
        rospy.loginfo("send msg:%d",msg.stamp.nsecs)
        rospy.loginfo("send msg:%d",msg.data)

        pub.publish(msg)
        cnt+=1
        loop_rate.sleep()

if __name__ =="__main__":
    try:
        msg_talker()

    except rospy.ROSInternalException:

        pass
