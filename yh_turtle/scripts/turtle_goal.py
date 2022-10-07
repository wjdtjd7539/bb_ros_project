#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math

class TurtleGoal:
    def __init__(self):
        self.sub=rospy.Subscriber("turtle1/pose",Pose,self.update_pose)
        self.pub=rospy.Publisher("turtle1/cmd_vel",Twist,queue_size=100)
        #pose란 움직이는값을수치화시킨것 cmd_vel은 속도조절하는것
        self.pose=Pose()
        self.goal_pose=Pose()
        self.loop_rate=rospy.Rate(10)

    def update_pose(self,msg):
        self.pose=msg
        self.pose.x=round(self.pose.x, 4)#소수점나오면반올림해주는것
        self.pose.y=round(self.pose.y, 4)#소수점4자리까지받는다
    
    def euclidean_distance(self):
        #점1->점2
        #self.pose----->self.goal_pose
        diff_x=self.goal_pose.x-self.pose.x
        diff_y=self.goal_pose.y-self.pose.y
        return math.sqrt((diff_x* diff_x) + (diff_y* diff_y))

    def linear_vel(self, constant=1.5):#constant=1.5는디폴트값이다
        return constant * self.euclidean_distance()

    def steering_angle(self):
        return math.atan2((self.goal_pose.y-self.pose.y),(self.goal_pose.x-self.pose.x))
        #아크탄젠트즉 세타를구할수있다 탄제트에 역함수취한것 y거리 x거리넣고돌리면
        #아크탄젠트구해준다

    def angular_vel(self,constant=6):
        return constant * (self.steering_angle()- self.pose.theta)
        #목표각도


    def run(self):
        self.goal_pose.x=float(input("x 좌표: "))
        self.goal_pose.y=float(input("y 좌표: "))

        tolerance=float(input("오차: "))

        msg=Twist()

        while self.euclidean_distance()>=tolerance:
            msg.linear.x=self.linear_vel()#직진vel은 벨로시티
            msg.angular.z=self.angular_vel()#각도
            

            self.pub.publish(msg)
            self.loop_rate.sleep()

        msg.linear.x=0
        msg.angular.z=0
        self.pub.publish(msg)
        rospy.loginfo("Goal")
    
if __name__ =="__main__":
    rospy.init_node("turtle_goal")
    turtle_goal = TurtleGoal()
    turtle_goal.run()







        
        
        #self.goal_x=float(input("x: "))
        #self.goal_y=float(input("y: "))
        #self.goal_theta=float(input("theta: "))
        #목표값설정