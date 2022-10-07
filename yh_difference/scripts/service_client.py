#!/usr/bin/python3
#-*- coding:utf-8 -*-

import rospy
from yh_difference.srv import YhDifference
import sys

def maxminminus():
    rospy.init_node("service_client")

    if len(sys.argv)!=3:
        rospy.loginfo("rosrun yh_difference service_client.py a b")
        rospy.loginfo("a,b:int32 number")
        sys.exit(1)

service_client=rospy.ServiceProxy("max-min",YhDifference)

req=YhDifference()

req.a=int(sys.argv[1])
req.b=int(sys.argv[2])

try:
    res=maxminminus(req)
    rospy.loginfo(f"a:{req.a},b{req.b},result:{res.result}")
except rospy.ServiceException as e:
    rospy.logerr(f"Fail:{e}")

if __name__=="__main__":
    maxminminus()
