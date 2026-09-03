#include "agt_lidar_filter/filters/blind_radius_filter.hpp"

#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

#include <cmath>

namespace agt_lidar_filter
{

BlindRadiusFilter::BlindRadiusFilter()
: radius_(0.8)
{
}

std::string BlindRadiusFilter::name() const
{
  return "blind_radius";
}

bool BlindRadiusFilter::configure(const std::string & namespace_name)
{
  (void)namespace_name;
  return true;
}

bool BlindRadiusFilter::process(
  const sensor_msgs::msg::PointCloud2 & input,
  sensor_msgs::msg::PointCloud2 & output)
{
  pcl::PointCloud<pcl::PointXYZI> cloud;
  pcl::fromROSMsg(input, cloud);

  pcl::PointCloud<pcl::PointXYZI> filtered;
  filtered.reserve(cloud.size());

  for (const auto & point : cloud.points) {
    const double distance = std::sqrt(
      point.x * point.x +
      point.y * point.y +
      point.z * point.z);

    if (distance >= radius_) {
      filtered.push_back(point);
    }
  }

  pcl::toROSMsg(filtered, output);
  output.header = input.header;
  return true;
}

}
