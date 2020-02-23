#ifndef KIMERA_ROS__INTERFACES__BACKEND_INTERFACE_HPP_
#define KIMERA_ROS__INTERFACES__BACKEND_INTERFACE_HPP_

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "kimera_vio_ros/interfaces/base_interface.hpp"
#include "tf2_ros/transform_broadcaster.h"

namespace kimera_vio_ros
{
namespace interfaces
{

class BackendInterface : public BaseInterface
{
public:
  BackendInterface(
    rclcpp::Node & node);
  ~BackendInterface();

public:
  inline void callbackBackendOutput(const VIO::BackendOutput::Ptr & output)
  {
    backend_output_queue_.push(output);
  }

protected:
  void publishBackendOutput(const VIO::BackendOutput::Ptr & output);

protected:
  VIO::ThreadsafeQueue<VIO::BackendOutput::Ptr> backend_output_queue_;

private:
  void publishTf(const VIO::BackendOutput::Ptr & output);
  // void publishTimeHorizonPointCloud(const VIO::BackendOutput::Ptr& output) const;
  // void publishState(const VIO::BackendOutput::Ptr& output) const;
  // void publishImuBias(const VIO::BackendOutput::Ptr& output) const;

private:
  tf2_ros::TransformBroadcaster tf_broadcaster_;

};

}  // namespace interfaces
}  // namespace kimera_vio_ros

#endif  // KIMERA_ROS__INTERFACES__BACKEND_INTERFACE_HPP_