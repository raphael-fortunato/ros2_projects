# Chat Room Node

This project implements a simple chat room node using ROS2 and C++. It allows multiple users to send and receive chat messages in a ROS2 environment.

## Project Structure

```
chat_room_node
├── src
│   ├── chat_node.cpp        # Implementation of the chat room node
├── include
│   └── chat_room_node
│       └── chat_node.hpp    # Header file for the ChatNode class
├── CMakeLists.txt           # CMake configuration file
├── package.xml              # ROS2 package metadata
└── README.md                # Project documentation
```

## Prerequisites

- ROS2 installed on your system
- C++ development environment

## Building the Project

1. Navigate to the project directory:
   ```
   cd chat_room_node
   ```

2. Build the project using colcon:
   ```
   colcon build
   ```

3. Source the setup file:
   ```
   source install/setup.bash
   ```

## Running the Chat Room Node

To run the chat room node, use the following command:
```
ros2 run chat_room_node chat_node
```

## Usage

Once the node is running, you can send and receive messages. Ensure that multiple instances of the node are running to simulate a chat room environment.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.