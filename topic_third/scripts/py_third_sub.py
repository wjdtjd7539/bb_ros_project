#!/usr/bin/python
#-*- coding:utf-8-*-

import rospy
from std_msgs.msg import Int64


def msgCallback(msg):
    rospy.loginfo("msg: %d" ,msg.data)

def my_listener():
    rospy.init_node("py_second_sub")
    rospy.Subscriber("mymy_count",Int64,msgCallback, queue_size=100)
    #rospy.Publisher(topic_name, msg_class, queue_size)
    #출판자혹은받는자를정의할때쓰는 형태이다

    rospy.spin()#콜벡오기를기다린다는뜻이다


if __name__=="__main__":
    my_listener()
