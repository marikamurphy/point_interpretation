/* This is where all things ros should go.  I would be ideal if we
 * didn't have to use ros anywhere but this file.
 */

#include <SubscribeToKinect.h>

using namespace std;

/* Constructor*/
SubscribeToKinect::SubscribeToKinect() {}

/* Return the color and depth image (in that order) in a vector. */
vector<cv::Mat> SubscribeToKinect::get_color_and_depth() {
    vector<cv::Mat> ret;
    ret.push_back(color_image);
    ret.push_back(depth_image);
    return ret;
}

void SubscribeToKinect::save_cv_mats(const sensor_msgs::Image::ConstPtr &color, const sensor_msgs::Image::ConstPtr &depth) {
    // color_image = *color.clone();
    // depth_image = *depth.clone();
    std::cout <<"Inside save_cv_mats"<< std::endl;
    color_image = cv_bridge::toCvCopy(color, sensor_msgs::image_encodings::BGR8)->image;
    depth_image = cv_bridge::toCvCopy(depth, sensor_msgs::image_encodings::BGR8)->image;
}

/* Get camera calibration values.  The values are in the order of ???? */
void SubscribeToKinect::camera_info_callback(const sensor_msgs::CameraInfo::ConstPtr &msg) {
    vector<double> ret;
    ret.push_back(msg->K[0]);
    ret.push_back(msg->K[4]);
    ret.push_back(msg->K[2]);
    ret.push_back(msg->K[5]);
    //return ret;
}

    // Just pass in argc and argv from main program
vector<cv::Mat> logic(int argc, char **argv, bool FLAGS_disable_multi_thread) {

        // Run openposes on the cv mats: TODO much later
}

        // Use in open pose code
        // op::Wrapper opWrapper{op::ThreadManagerMode::Asynchronous};
        // try {
        //     // Use single thread for debugging
        //     if (FLAGS_disable_multi_thread) {
        //        opWrapper.disableMultiThreading();
        //     } //only use if openpose build with flags enabled
            
        //     op::WrapperStructPose wrapperStructPose{};
        //     wrapperStructPose.modelFolder = op::String("openpose/models");
            
        //     opWrapper.configure(wrapperStructPose);
        //     opWrapper.start();
        //     op::PoseModel& poseModel = wrapperStructPose.poseModel;
        //     const auto& pbpmBody25 = getPoseBodyPartMapping(poseModel);
        //     // std::cout << "get 3 (relbow?) " << pbpmBody25.at(3) << std::endl; 
        //     // std::cout << "get 4 (rwrist?) " << pbpmBody25.at(4) << std::endl;
        //     // std::cout << "pose model: " << static_cast<int>(poseModel) << std::endl;
        // } catch (const std::exception& e) {
        //     return -1;
        // }
