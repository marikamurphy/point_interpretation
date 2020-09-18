cmake_minimum_required(VERSION 3.0)
project(point)


find_package (
Eigen3 3.3 REQUIRED)
find_package(
    OpenCV
)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  message_filters
  cv_bridge
  # tf2
  # tf2_ros
  
  # rospy
  # geometry_msgs
  # image_transport
  
  # visualization_msgs
)

catkin_package(
#   INCLUDE_DIRS include
#   LIBRARIES point_interpretation
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_LIBS}

)
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(
    point 
    src/point_interpretation.cpp
    src/Client.cpp
    src/SubscribeToKinect.cpp
)

target_link_libraries (point ${OpenCV_LIBS} ${catkin_LIBRARIES} Eigen3::Eigen    )
