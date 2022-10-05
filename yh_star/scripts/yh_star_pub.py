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


    while not rospy.is_shutdown(): #노드가 종료를 시작하려고 할 때 rospy.on_shutdown() 을 사용하여 콜백을 요청할 수 있습니다 . 
        #이는 실제 종료되기 전에 호출되므로 서비스 및 매개변수 서버 호출을 안전하게 수행할 수 있습니다. 메시지 게시가 보장되지 않습니다.
        #while not은 반대로 조건문이 참이 아닌 동안에만 해당 코드가 반복적으로 실행되게 
        # 코드를 작성할 수도 있다.
         #while not rospy.is_shutdown()>rospy.is shutdown()를확인하면서 루프를돌리게된다
        #즉사용자가ctrl+c를눌러작동을멈추기전까지는계속루프를돌린다는의미이다
        msg.stamp=rospy.Time.now()#시간을사용할때쓰는 라이브러리
        msg.data=cnt
        rospy.loginfo("send msg:%d",msg.stamp.secs)#이는세가지를 실행한다 첫째화면에프린트한다
        #둘째노드의로그파일에기록한다섹째rosout에기록한다 rosout에기록된내용으로디버깅이유용해진다.
        rospy.loginfo("send msg:%d",msg.stamp.nsecs)#10억분의1초
        rospy.loginfo("send msg:%d",msg.data)

        pub.publish(msg)
        cnt+=1#count약자
        loop_rate.sleep()

if __name__ =="__main__":
    try:
        msg_talker()

    except rospy.ROSInternalException:#예외처리

        pass
