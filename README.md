# agt_lidar_filter

ROS 2 LiDAR preprocessing framework for mobile robots.

## Project Positioning

`agt_lidar_filter` is an independent sensor preprocessing layer. It is responsible for converting raw LiDAR point cloud data into a stable and configurable input stream for downstream modules such as:

- FAST-LIO / FAST-LIO2
- FAST-LIVO / FAST-LIVO2
- SLAM systems
- Navigation systems
- Perception systems

The package is **not coupled** with any specific LiDAR vendor, SLAM algorithm, or navigation framework.

## Design Goal

Provide a reusable ROS 2 component framework for evaluating and deploying different LiDAR filtering strategies, especially for mobile robots using Livox MID360 where self-reflection and near-field interference are common.

## Supported Scope

### Included

- PointCloud2 input/output pipeline
- Configurable filter chain
- Near-field blind radius filtering
- Spatial region filtering (CropBox)
- Angular field-of-view masking
- Voxel downsampling
- Filtering statistics and benchmarking interface

### Explicitly Not Included

- SLAM algorithms
- Mapping algorithms
- Dynamic object tracking
- Semantic segmentation
- Robot collision model management
- Navigation costmap logic

## Pipeline Concept

```
Raw PointCloud2
       |
       v
agt_lidar_filter pipeline
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
Filtered PointCloud2
```

## ROS Interface Concept

Input:

```
/sensor/lidar/points
```

Output:

```
/agt_lidar_filter/points
```

Statistics:

```
/agt_lidar_filter/statistics
```

## Configuration Philosophy

Different filtering strategies should be switchable only through configuration files.

Example profiles:

```
config/
 ├── mid360_raw.yaml
 ├── mid360_blind.yaml
 ├── mid360_cropbox.yaml
 ├── mid360_angular.yaml
 └── mid360_combined.yaml
```

The same rosbag should be able to run through different profiles for objective comparison.

## Roadmap

### v0.1.0 Architecture Freeze

- Define filter interfaces
- Define ROS interfaces
- Define configuration format
- Define benchmark format

### v0.2.0 Basic Filters

- Blind radius filter
- CropBox filter
- Angular mask filter
- Voxel filter

### v0.3.0 Evaluation Tools

- Point count statistics
- Processing latency statistics
- RViz comparison workflow
- FAST-LIO integration test

