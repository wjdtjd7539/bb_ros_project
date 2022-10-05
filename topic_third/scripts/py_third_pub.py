#!/usr/bin/python
#-*- coding:utf-8-*-

import rospy
from std_msgs.msg import Int64


def mymy_counter():
    rospy.init_node("py_third_pub")#노드초기화
    pub= rospy.Publisher("mymy_count", Int64,queue_size=100)
    #rospy.Publisher(topic_name, msg_class, queue_size)
    #출판자혹은받는자를정의할때쓰는 형태이다
    
    loop_rate=rospy.Rate(4)

    msg=Int64()
    msg.data=0

    while not rospy.is_shutdown():
        pub.publish(msg)
        loop_rate.sleep() #hz에맞게 쉬는동작
        msg.data+=1
        #노드가 종료를 시작하려고 할 때 rospy.on_shutdown() 을 사용하여 콜백을 요청할 수 있습니다 . 
        #이는 실제 종료되기 전에 호출되므로 서비스 및 매개변수 서버 호출을 안전하게 수행할 수 있습니다. 메시지 게시가 보장되지 않습니다.
        #while not은 반대로 조건문이 참이 아닌 동안에만 해당 코드가 반복적으로 실행되게 
        # 코드를 작성할 수도 있다.
        #https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=passionvirus&logNo=80130186966
        #while not rospy.is_shutdown()>rospy.is shutdown()를확인하면서 루프를돌리게된다
        #즉사용자가ctrl+c를눌러작동을멈추기전까지는계속루프를돌린다는의미이다.
if  __name__ =="__main__":
    try:
        mymy_counter()
    except rospy.ROSInterruptException:
        pass




