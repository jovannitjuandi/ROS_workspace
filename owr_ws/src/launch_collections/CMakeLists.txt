cmake_minimum_required(VERSION 3.0.2)
project(launch_collections)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  roslaunch
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)