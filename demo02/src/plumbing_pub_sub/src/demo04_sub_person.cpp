#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h" // 包含自定义消息的头文件
void doPerson(const plumbing_pub_sub::Person::ConstPtr& msg) {
    // 回调函数处理接收到的消息
    ROS_INFO("接收到的数据是：name=%s, age=%d, height=%.2f", msg->name.c_str(), msg->age, msg->height);
}
int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    ROS_INFO("订阅方开始运行");
    ros::init(argc,argv,"jiazhang"); // 初始化ROS节点
    ros::NodeHandle nh; // 创建节点句柄
    ros::Subscriber sub = nh.subscribe("liaotian", 10, doPerson) ;
    ros::spin(); // 进入循环，等待回调函数处理消息
    return 0;
}