#pragma once

#include <memory>
#include <vector>
#include "agt_lidar_filter/filter_base.hpp"

namespace agt_lidar_filter
{

class FilterPipeline
{
public:
  void addFilter(std::shared_ptr<PointCloudFilter> filter);

  bool process(
    const sensor_msgs::msg::PointCloud2 & input,
    sensor_msgs::msg::PointCloud2 & output);

private:
  std::vector<std::shared_ptr<PointCloudFilter>> filters_;
};

}
