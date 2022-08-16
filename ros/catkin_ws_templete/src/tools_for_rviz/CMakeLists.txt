cmake_minimum_required(VERSION 2.8.3)
project(tools_for_rviz)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
)

set(PACKAGE_DEPENDENCIES
  roscpp
  sensor_msgs
  pcl_ros
  pcl_conversions
  std_srvs
  message_generation 
  std_msgs
  rosbag
  eigen_conversions
  message_filters
)

find_package(PCL 1.3 REQUIRED COMPONENTS common io)
find_package(catkin REQUIRED COMPONENTS ${PACKAGE_DEPENDENCIES})


catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}  ${PCL_INCLUDE_DIRS} 
)


link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(dynamic_tf_pub src/dynamic_tf_pub.cpp)
target_link_libraries(dynamic_tf_pub ${catkin_LIBRARIES})

add_executable(track_display_apollo src/track_display_apollo.cpp)
target_link_libraries(track_display_apollo ${catkin_LIBRARIES})


