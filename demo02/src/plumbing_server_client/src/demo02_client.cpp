#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc, char *argv[]) {

    setlocale(LC_ALL, ""); // 设置中文环境
    if(argc!=3){
        ROS_INFO("提交参数个数不正确，应该是两个整数");
        return 1;
    }

    ros::init(argc, argv, "heshui_client");
    ros::NodeHandle nh;
    // 创建服务端，注册服务名为"add_ints"，服务类型为AddInts
    ros::ServiceClient client=nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    plumbing_server_client::AddInts srv; // 创建服务请求对象
    srv.request.num1 = atoi(argv[1]); // 设置请求的第一个整数
    srv.request.num2 = atoi(argv[2]); // 设置请求的第二个整数
    client.waitForExistence(); // 等待服务端存在
    client.call(srv); // 调用服务
    bool flag=client.call(srv); // 调用服务
    if (flag) {
        ROS_INFO("服务调用成功，结果是：%d", srv.response.sum); // 输出结果
    }
    return 0;
}