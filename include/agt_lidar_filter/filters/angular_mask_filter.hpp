#pragma once

#include "agt_lidar_filter/filter_base.hpp"

namespace agt_lidar_filter
{

class AngularMaskFilter : public PointCloudFilter
{
public:
  AngularMaskFilter();

  std::string name() const override;

  bool configure(const std::string & namespace_name) override;

  bool process(
    const sensor_msgs::msg::PointCloud2 & input,
    sensor_msgs::msg::PointCloud2 & output) override;

private:
  double min_pitch_{-45.0};
  double max_pitch_{45.0};
};

}
