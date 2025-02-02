#include "chat_room_node/chat_node.hpp"

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>
using namespace std::chrono_literals;

ChatNode::ChatNode() : Node("chat_node") {
    RCLCPP_INFO(this->get_logger(), "Chat node has been started.");
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
        10s, std::bind(&ChatNode::publish_message, this));
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic", 10,
        std::bind(&ChatNode::message_callback, this, std::placeholders::_1));
}

void ChatNode::message_callback(const std_msgs::msg::String::SharedPtr msg) {
    auto message = msg->data;
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", message.c_str());
    std::cout << "I heard: " << message << std::endl;
}

void ChatNode::publish_message() {
    RCLCPP_INFO(this->get_logger(), "Please enter a message: ");
    auto message = std_msgs::msg::String();
    std::getline(std::cin, message.data);
    publisher_->publish(message);
}
int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ChatNode>());
    rclcpp::shutdown();
    return 0;
}

