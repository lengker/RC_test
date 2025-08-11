#include "ros/ros.h"
int main(int argc, char *argv[]) {
    
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "param_get");
    ros::NodeHandle nh;
    double radius=nh.param("radius", 0.5); // 获取参数，默认值为0.5
    ROS_INFO("获取到的半径参数是：%f", radius);
    double radius2=0.0;
    bool result = nh.getParam("radius", radius2); // 获取参数
    if (result) {
        ROS_INFO("获取到的半径参数是：%f", radius2);
    } else {
        ROS_WARN("未能获取到半径参数");
    }
    return 0;
}