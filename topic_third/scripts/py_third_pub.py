#!/usr/bin/python
#-*- coding:utf-8-*-

import rospy
from std_msgs.msg import Int64


def mymy_counter():
    rospy.init_node("py_third_pub")
    pub= rospy.Publisher("mymy_count", Int64,queue_size=100)
    
    loop_rate=rospy.Rate(4)

    msg=Int64()
    msg.data=0

    while not rospy.is_shutdown():
        pub.publish(msg)
        loop_rate.sleep() #hz에맞게 쉬는동작
        msg.data+=1

if  __name__ =="__main__":
    try:
        mymy_counter()
    except rospy.ROSInterruptException:
        pass




