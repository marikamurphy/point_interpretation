#ifndef SUBSCRIBE_TO_KINECT_H
#define SEUBSCRIBE_TO_KINECT_H

#include <opencv2/core/mat.hpp> // cv::Mat
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/sync_policies/exact_time.h>
#include <ros/ros.h> // Ros functionalities
#include <sensor_msgs/CameraInfo.h> 
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Image.h>
#include <visualization_msgs/Marker.h>
#include <cv_bridge/cv_bridge.h>

using namespace std;

class SubscribeToKinect {
    private:
        

    public:
        SubscribeToKinect();
        vector<cv::Mat> get_color_and_depth();
        void save_cv_mats(const sensor_msgs::Image::ConstPtr &color, const sensor_msgs::Image::ConstPtr &depth);
        void camera_info_callback(const sensor_msgs::CameraInfo::ConstPtr &msg);
        ros::Publisher marker_pub;
        cv::Mat depth_image;
        cv::Mat color_image;
};

#endif