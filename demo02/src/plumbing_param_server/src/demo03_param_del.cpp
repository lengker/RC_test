#include "ros/ros.h"
int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "");
    ros::init(argc, argv, "param_del");
    ros::NodeHandle nh;

    // 删除参数
    bool flag1 = nh.deleteParam("type");
    if(flag1) {
        ROS_INFO("删除参数 type 成功");
    } else {
        ROS_WARN("删除参数 type 失败，参数可能不存在");
    }
    nh.deleteParam("radius");
    ros::param::del("type_param"); // 删除全局参数
    ros::param::del("radius_param"); // 删除全局参数

    ROS_INFO("参数删除完成");

    return 0;
}