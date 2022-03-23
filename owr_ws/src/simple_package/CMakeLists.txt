cmake_minimum_required(VERSION 3.0.2)
project(simple_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  roslaunch
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker src/publisher.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/subscriber.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
