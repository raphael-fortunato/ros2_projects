cmake_minimum_required(VERSION 3.5)
project(chat_room_node)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

# Create executable
add_executable(chat_node src/chat_node.cpp)

# Link libraries
ament_target_dependencies(chat_node rclcpp std_msgs)

# Install targets
install(TARGETS
  chat_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()