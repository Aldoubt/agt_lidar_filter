#pragma once

#include <memory>
#include <string>
#include "agt_lidar_filter/filter_base.hpp"

namespace agt_lidar_filter
{

class FilterFactory
{
public:
  static std::shared_ptr<PointCloudFilter> create(const std::string & type);
};

}
