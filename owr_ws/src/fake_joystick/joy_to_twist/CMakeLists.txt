cmake_minimum_required(VERSION 3.0.2)
project(joy_to_twist)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package( CATKIN_DEPENDS roscpp rospy std_msgs )

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(joy_to_vel src/joy_to_vel.cpp)
target_link_libraries(joy_to_vel ${catkin_LIBRARIES})