#include "agt_lidar_filter/filter_pipeline.hpp"

namespace agt_lidar_filter
{

void FilterPipeline::addFilter(std::shared_ptr<PointCloudFilter> filter)
{
  if (filter) {
    filters_.push_back(filter);
  }
}

bool FilterPipeline::process(
  const sensor_msgs::msg::PointCloud2 & input,
  sensor_msgs::msg::PointCloud2 & output)
{
  sensor_msgs::msg::PointCloud2 current = input;

  for (auto & filter : filters_) {
    sensor_msgs::msg::PointCloud2 next;
    if (!filter->process(current, next)) {
      return false;
    }
    current = next;
  }

  output = current;
  return true;
}

}
