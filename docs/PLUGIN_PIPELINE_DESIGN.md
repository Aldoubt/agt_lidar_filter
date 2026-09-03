# Filter Plugin Pipeline Design

## Goal

agt_lidar_filter uses a plugin-style preprocessing pipeline. The core node does not know specific LiDAR filtering algorithms.

## Data flow

```
PointCloud2 input
        |
        v
FilterPipeline
        |
        +-- BlindRadiusFilter
        |
        +-- CropBoxFilter
        |
        +-- AngularMaskFilter
        |
        +-- VoxelFilter
        |
        v
PointCloud2 output
```

## Interface

All filters implement:

- name()
- configure()
- process(input, output)

## Current MID360 target filters

### blind_radius

Remove points close to sensor origin.

### cropbox

Remove fixed robot body regions.

### angular_mask

Remove points according to sensor yaw/pitch direction. Suitable for tilted MID360 installation.

### voxel

Control point density before SLAM.

## Future extension

The same interface can support:

- ground filtering
- semantic filtering
- dynamic object filtering
- intensity filtering

without changing ROS interfaces.
