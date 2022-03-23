cmake_minimum_required(VERSION 3.0.2)
project(keyboard_to_joystick)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package( CATKIN_DEPENDS roscpp rospy std_msgs )

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(key_to_joy src/key_to_joy.cpp)
target_link_libraries(key_to_joy ${catkin_LIBRARIES})