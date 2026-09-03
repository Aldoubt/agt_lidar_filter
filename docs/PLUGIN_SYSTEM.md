# Filter Plugin System

## Goal

`agt_lidar_filter` uses a pipeline architecture. The ROS node does not depend on concrete filtering algorithms.

## Runtime flow

```
PointCloud2 input
        |
        v
 FilterPipeline
        |
        +--> FilterFactory
        |
        +--> blind_radius
        |
        +--> cropbox
        |
        +--> angular_mask
        |
        +--> voxel
        |
        v
PointCloud2 output
```

## Configuration concept

Example:

```yaml
filters:
  - type: blind_radius
  - type: cropbox
```

The factory creates filters by name. This allows comparing different MID360 preprocessing strategies using identical rosbag data.

## Boundary

This package handles sensor preprocessing only.

It does not implement:

- SLAM
- localization
- navigation
- semantic perception
- map generation
