#include "ros/ros.h"
#include "std_msgs/String.h"
int main(int argc,char *argv[]){
    ros::init(argc,argv,"ergouzi");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);
    std_msgs::String msg;
    ros::Rate rate(10);
    int count = 0;
    ros::Duration(3).sleep(); // 等待2秒，确保订阅者可以连接上
    while(ros::ok()){
        setlocale(LC_ALL,"");
        count++;
        //msg.data = "hello world";
        std::stringstream ss;
        ss <<"hello world " << count;
        msg.data = ss.str();
        ROS_INFO("发布的数据是：%s",msg.data.c_str());
        pub.publish(msg);
        rate.sleep();
        ros::spinOnce(); // 处理回调函数
    }
    return 0;

}