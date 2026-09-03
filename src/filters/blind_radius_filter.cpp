#include "agt_lidar_filter/filters/blind_radius_filter.hpp"

#include <cmath>
#include <sensor_msgs/point_cloud2_iterator.hpp>

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

bool BlindRadiusFilter::configure(double radius)
{
  radius_ = radius;
  return true;
}

bool BlindRadiusFilter::process(
  const sensor_msgs::msg::PointCloud2 & input,
  sensor_msgs::msg::PointCloud2 & output)
{
  output = input;

  sensor_msgs::PointCloud2Modifier modifier(output);
  modifier.resize(0);

  sensor_msgs::PointCloud2Modifier input_modifier(output);
  (void)input_modifier;

  return true;
}

}
