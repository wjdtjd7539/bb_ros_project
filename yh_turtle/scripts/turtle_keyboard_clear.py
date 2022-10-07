#!/usr/bin/python3
#-*- coding: utf-8 -*-

import rospy

from geometry_msgs.msg import Twist
from std_msgs.msg import Empty
from turtle_keyboard import Turtlekeyboard
from turtle_clear import TurtleClear




class TurtlekeyboardClear(Turtlekeyboard,TurtleClear):
    def __init__(self):
        Turtlekeyboard.__init__(self)
        TurtleClear.__init__(self)


    def msgCallback(self, msg):
        if msg.linear.z>0.0:
            self.call()
        else:
            self.pub.publish(msg)

if __name__=="__main__":
    rospy.init_node("turtle_keyboard_clear")
    turtle_keyboard_clear=TurtlekeyboardClear()
    
    rospy.spin()



 