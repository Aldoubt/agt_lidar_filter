#pragma once

#include <string>
#include <sensor_msgs/msg/point_cloud2.hpp>

namespace agt_lidar_filter
{

class PointCloudFilter
{
public:
  virtual ~PointCloudFilter() = default;

  virtual std::string name() const = 0;

  virtual bool configure(const std::string & parameter_namespace) = 0;

  virtual bool process(
    const sensor_msgs::msg::PointCloud2 & input,
    sensor_msgs::msg::PointCloud2 & output) = 0;
};

}
