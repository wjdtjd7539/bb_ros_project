#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from yh_check.msg import YhCheck

class MyCheck:
    def __init__(self):         
        #self는마이체크의인스턴스
        self.sub_distance=rospy.Subscriber("check_distance",YhCheck,self.distanceCallback)
        self.sub_camera=rospy.Subscriber("check_camera",YhCheck,self.cameraCallback)

        self.sub_distance=True
        self.camera=True

    def distanceCallback(self,msg):
        self.distance = msg.data    
        #data에 True가들어있다
        if self.distance and self.camera:
            rospy.loginfo("ok")
    
    def cameraCallback(self,msg):
        self.camera=msg.data
        if self.distance and self.camera:
            rospy.loginfo("ok")

if __name__ == "__main__":
    rospy.init_node("yh_check_sub")
    my_check= MyCheck()

    rospy.spin()
















































#class Calculator:
    #def __init__(self):
    #    self.result = 0
    
    #def add(self, num):
    #    self.result +=num
    #    return self.result
    
    #def sub(self,num):
    #    self.result -=num
    #    return self.result
    
    #def mul(self,num):
    #    self.result *=num
    #    return self.result
    #def div(self,num):
    #    return self.result/num#result에저장되지않고 앞의result값이그대로남아있다

#cal=Calculator()#칼큘레이터의 인스턴스cal이있다

#class MyCalculator(Calculator):


#print(cal.add(4))
#print(cal.add(1))
#print(cal.add(5))
#print(cal.add(8))
#print(cal.add(-14))
#print(cal.add(40))# result에 계속값이저장되서 44가나온다 그래서class를쓰는이유이다



