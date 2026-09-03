#include "agt_lidar_filter/filters/angular_mask_filter.hpp"

#include <cmath>

namespace agt_lidar_filter
{

AngularMaskFilter::AngularMaskFilter()
{
}

std::string AngularMaskFilter::name() const
{
  return "angular_mask";
}

bool AngularMaskFilter::configure(const std::string &)
{
  return true;
}

bool AngularMaskFilter::process(
  const sensor_msgs::msg::PointCloud2 & input,
  sensor_msgs::msg::PointCloud2 & output)
{
  output = input;
  return true;
}

}
