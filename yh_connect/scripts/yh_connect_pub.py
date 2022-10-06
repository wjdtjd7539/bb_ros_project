#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from std_msgs.msg import Int32

class ConnectPub:
    def __init__(self):
        self.pub=rospy.Publisher("yh_connect_int",Int32)
        #퍼블리셔선언 노드이름과 자료형이필요하다
        self.msg=Int32()
        #connect_pub의 ㅡmsg instance Int32로 필요한다 위에int32와다르다(통신을하기위함)
        self.loop_rate=rospy.Rate(4)
        #루프속도

    def run(self):
        while not rospy.is_shutdown():
            #꺼지지않으면계속돈다
         #while not rospy.is_shutdown()>rospy.is shutdown()를확인하면서 루프를돌리게된다
        #즉사용자가ctrl+c를눌러작동을멈추기전까지는계속루프를돌린다는의미이다.
            self.pub.publish(self.msg)
            self.msg.data +=1
            self.loop_rate.sleep()

if __name__=="__main__":
    rospy.init_node("yh_connect_pub")
    connect_pub=ConnectPub()
    connect_pub.run()

