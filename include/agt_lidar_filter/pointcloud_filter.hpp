#pragma once

#include <string>
#include <sensor_msgs/msg/point_cloud2.hpp>

namespace agt_lidar_filter {

class PointCloudFilter
{
public:
  virtual ~PointCloudFilter() = default;

  virtual std::string name() const = 0;

  virtual void configure() = 0;

  virtual void process(
    const sensor_msgs::msg::PointCloud2 & input,
    sensor_msgs::msg::PointCloud2 & output) = 0;
};

}
