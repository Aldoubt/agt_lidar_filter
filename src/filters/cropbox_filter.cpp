#include "agt_lidar_filter/filters/cropbox_filter.hpp"

namespace agt_lidar_filter
{

CropBoxFilter::CropBoxFilter()
{
}

std::string CropBoxFilter::name() const
{
  return "cropbox";
}

bool CropBoxFilter::configure(const std::string & namespace_name)
{
  (void)namespace_name;
  return true;
}

bool CropBoxFilter::process(
  const sensor_msgs::msg::PointCloud2 & input,
  sensor_msgs::msg::PointCloud2 & output)
{
  output = input;
  return true;
}

}
