cmake_minimum_required(VERSION 3.0.2)
project(bridges)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  roscpp
)

catkin_package(
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(subAndPub src/subAndPub.cpp)
target_link_libraries(subAndPub ${catkin_LIBRARIES})


add_executable(subAndPub_class src/subAndPub_class.cpp)
target_link_libraries(subAndPub_class ${catkin_LIBRARIES})