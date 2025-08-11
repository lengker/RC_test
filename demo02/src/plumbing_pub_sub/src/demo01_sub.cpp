#include "ros/ros.h"
#include "std_msgs/String.h"
void doMsg(const std_msgs::String::ConstPtr &msg) {
    ROS_INFO("翠花订阅的数据：%s", msg->data.c_str());
}
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, ""); // 设置中文环境
    ros::init(argc, argv, "cuihua");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("fang", 10, doMsg); 
    ros::spin(); // 进入循环，等待订阅消息
    return 0;
}