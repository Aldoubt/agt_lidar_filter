#pragma once

#include <memory>
#include <string>

#include "agt_lidar_filter/filter_base.hpp"

namespace agt_lidar_filter
{

/**
 * Runtime factory for filter plugins.
 *
 * The factory isolates node/pipeline logic from concrete filters.
 * Future implementations may create filters from yaml names such as:
 * - blind_radius
 * - cropbox
 * - angular_mask
 * - voxel
 */
class FilterFactory
{
public:
  static std::shared_ptr<PointCloudFilter> create(const std::string & type);
};

}  // namespace agt_lidar_filter
