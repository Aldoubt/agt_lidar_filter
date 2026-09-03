#include "agt_lidar_filter/filters/cropbox_filter.hpp"

#include <pcl/filters/crop_box.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>

namespace agt_lidar_filter
{

CropBoxFilter::CropBoxFilter()
{
}

std::string CropBoxFilter::name() const
{
  return "cropbox";
}

bool CropBoxFilter::configure(const std::string &)
{
  return true;
}

bool CropBoxFilter::process(
  const sensor_msgs::msg::PointCloud2 & input,
  sensor_msgs::msg::PointCloud2 & output)
{
  pcl::PointCloud<pcl::PointXYZ> cloud;
  pcl::PointCloud<pcl::PointXYZ> filtered;

  pcl::fromROSMsg(input, cloud);

  pcl::CropBox<pcl::PointXYZ> crop;
  crop.setInputCloud(cloud.makeShared());
  crop.setMin(Eigen::Vector4f(min_x_, min_y_, min_z_, 1.0f));
  crop.setMax(Eigen::Vector4f(max_x_, max_y_, max_z_, 1.0f));
  crop.filter(filtered);

  pcl::toROSMsg(filtered, output);
  output.header = input.header;

  return true;
}

}
