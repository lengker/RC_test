#include "ros/ros.h"
int main(int argc, char *argv[]){
    setlocale(LC_ALL, ""); // 设置本地化环境，支持中文输出
    ros::init(argc, argv, "hello_vscode");
    ROS_INFO("Hello, VSCode!哈哈");
    return 0;
}