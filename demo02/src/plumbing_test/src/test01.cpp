#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
int main(int argc, char *argv[]) {
    
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "turtle_controller");
    ros::NodeHandle nh;
    
    // 创建一个发布者，发布到"turtle1/cmd_vel"主题
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
    geometry_msgs::Twist twist_msg; // 创建一个Twist消息对象
    twist_msg.linear.x = 2.0;
    twist_msg.angular.z = 1.0; // 设置线速度和角速度
    ros::Rate rate(10); // 设置发布频率为10Hz
    
    while (ros::ok()) {
        pub.publish(twist_msg); // 发布Twist消息
        ROS_INFO("发布的速度：线速度=%.2f, 角速度=%.2f", twist_msg.linear.x, twist_msg.angular.z);
        rate.sleep(); // 按照设定的频率休眠
        ros::spinOnce(); // 处理回调函数
    }
    ROS_INFO("程序结束");
    // 释放资源
    pub.shutdown();
    ros::shutdown();
    ROS_INFO("发布者已关闭");
    // 返回0表示程序正常结束    
    return 0;
}