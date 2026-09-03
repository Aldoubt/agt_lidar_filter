cmake_minimum_required(VERSION 3.8)
project(agt_lidar_filter)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(PCL REQUIRED)

add_executable(lidar_filter_node src/lidar_filter_node.cpp)

ament_target_dependencies(lidar_filter_node
  rclcpp
  sensor_msgs
  pcl_conversions
)

target_include_directories(lidar_filter_node PUBLIC include)

target_link_libraries(lidar_filter_node ${PCL_LIBRARIES})

install(TARGETS lidar_filter_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
