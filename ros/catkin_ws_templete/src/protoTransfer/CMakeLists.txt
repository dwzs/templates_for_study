cmake_minimum_required(VERSION 3.0.2)
project(protoTransfer)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

find_package(Protobuf REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES protoTransfer
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)



add_executable(int_publisher_node src/int_publisher.cpp proto/person.pb.cc)
target_link_libraries(int_publisher_node ${catkin_LIBRARIES} ${PROTOBUF_LIBRARIES})

add_executable(int_subscriber_node src/int_subscriber.cpp proto/person.pb.cc)
target_link_libraries(int_subscriber_node ${catkin_LIBRARIES} ${PROTOBUF_LIBRARIES})
