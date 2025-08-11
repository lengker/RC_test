#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
bool doNums(plumbing_server_client::AddInts::Request &req, plumbing_server_client::AddInts::Response &res) {
    // 处理请求，计算两个整数的和
    res.sum = req.num1 + req.num2; // 计算和
    ROS_INFO("翠花请求的数字：%d 和 %d，结果是：%d", req.num1, req.num2, res.sum);
    return true; // 返回成功
}
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, ""); // 设置中文环境
    ros::init(argc, argv, "heshui_server");
    ros::NodeHandle nh;
    // 创建服务端，注册服务名为"add_ints"，服务类型为AddInts
    ros::ServiceServer service = nh.advertiseService("addInts",doNums) ;
    ROS_INFO("服务端已启动，等待客户端请求...");
    ros::spin(); // 进入循环，等待客户端请求
    return 0;
}