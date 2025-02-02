#ifndef CHAT_NODE_HPP
#define CHAT_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class ChatNode : public rclcpp::Node {
   public:
    ChatNode();

   private:
    void message_callback(const std_msgs::msg::String::SharedPtr msg);
    void publish_message();

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

#endif  // CHAT_NODE_HPP
