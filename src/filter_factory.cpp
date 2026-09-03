#include "agt_lidar_filter/filter_factory.hpp"
#include "agt_lidar_filter/filters/blind_radius_filter.hpp"
#include "agt_lidar_filter/filters/cropbox_filter.hpp"
#include "agt_lidar_filter/filters/angular_mask_filter.hpp"

namespace agt_lidar_filter
{

std::shared_ptr<PointCloudFilter> FilterFactory::create(const std::string & type)
{
  if (type == "blind_radius") {
    return std::make_shared<BlindRadiusFilter>();
  }

  if (type == "cropbox") {
    return std::make_shared<CropBoxFilter>();
  }

  if (type == "angular_mask") {
    return std::make_shared<AngularMaskFilter>();
  }

  return nullptr;
}

}
