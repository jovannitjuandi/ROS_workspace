cmake_minimum_required(VERSION 3.0.2)
project(keyboard_publisher)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package( CATKIN_DEPENDS roscpp rospy std_msgs )

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(keyboard src/keyboard_reader.cpp)
target_link_libraries(keyboard ${catkin_LIBRARIES})