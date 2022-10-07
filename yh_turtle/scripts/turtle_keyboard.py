#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist

class Turtlekeyboard:
    def __init__(self):
        self.sub=rospy.Subscriber("cmd_vel",Twist,self.msgCallback)
        self.pub=rospy.Publisher("turtle1/cmd_vel",Twist,queue_size=100)
        #Queue Size는 발행되는 메세지를 얼마나 가지고 있을지에 관련된 변수이며 신규 데이터가 들어오는 경우 오래된 데이터부터 삭제하게 된다.


    def msgCallback(self,msg):
        self.pub.publish(msg)

if __name__== "__main__":
    rospy.init_node("turtle_keyboard")
    turtle_keyboard =Turtlekeyboard()
    rospy.spin()
    rospy.speed(2)