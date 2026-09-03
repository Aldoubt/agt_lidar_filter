#include "agt_lidar_filter/filter_factory.hpp"
#include "agt_lidar_filter/filters/blind_radius_filter.hpp"

namespace agt_lidar_filter
{

std::shared_ptr<PointCloudFilter> FilterFactory::create(const std::string & type)
{
  if (type == "blind_radius") {
    return std::make_shared<BlindRadiusFilter>();
  }

  return nullptr;
}

}
