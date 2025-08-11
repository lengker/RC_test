#include "ros/ros.h"

int main(int argc, char *argv[]) {
    
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "param_set");
    ros::NodeHandle nh;

    // 设置参数
    nh.setParam("type", "xiaobai");
    nh.setParam("radius", 0.15);
    ros::param::set("type_param", "xiaohuang"); // 全局参数
    ros::param::set("radius_param", 0.15);  // 全局参数

    ros::param::set("radius",0.2);
    ros::param::set("type","xiao0.0");
    ROS_INFO("参数设置完成");

    return 0;
}