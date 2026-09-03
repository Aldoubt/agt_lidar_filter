# agt_lidar_filter Interface Design

## 1. Package Layering

```
agt_lidar_filter
|
+-- ROS Layer
|    +-- PointCloud2 subscriber
|    +-- PointCloud2 publisher
|    +-- parameter management
|
+-- Core Layer
|    +-- FilterPipeline
|    +-- FilterFactory
|    +-- FilterPlugin interface
|
+-- Filter Plugins
     +-- BlindRadiusFilter
     +-- CropBoxFilter
     +-- AngularMaskFilter
     +-- VoxelFilter
```

## 2. Core Interface

All filters implement the same interface.

Conceptual API:

```cpp
class PointCloudFilter
{
public:
    virtual ~PointCloudFilter() = default;

    virtual void configure(const FilterConfig & config) = 0;

    virtual void process(
        const PointCloudInput & input,
        PointCloudOutput & output) = 0;

    virtual std::string name() const = 0;
};
```

## 3. Pipeline Interface

The pipeline controls execution order.

Conceptual API:

```
FilterPipeline

add_filter(filter)

process(input_cloud)

get_statistics()
```

Example:

```
input
 |
BlindRadiusFilter
 |
CropBoxFilter
 |
VoxelFilter
 |
output
```

## 4. Filter Definitions

## BlindRadiusFilter

Purpose:

Remove points close to LiDAR origin.

Typical usage:

- MID360 self reflection
- mounting structure removal

Parameters:

```yaml
radius: 0.8
```

---

## CropBoxFilter

Purpose:

Remove fixed spatial regions around robot body.

Parameters:

```yaml
min:
  x: -1.0
  y: -1.0
  z: -0.5
max:
  x: 1.0
  y: 1.0
  z: 0.5
```

---

## AngularMaskFilter

Purpose:

Remove specific sensor viewing angles.

Designed for tilted LiDAR installation.

Parameters:

```yaml
yaw:
  min: -180
  max: 180
pitch:
  min: -45
  max: 20
```

---

## VoxelFilter

Purpose:

Optional point density normalization.

Parameters:

```yaml
leaf_size: 0.1
```

## 5. Configuration Interface

Example:

```yaml
pipeline:
  - blind_radius
  - cropbox

filters:
  blind_radius:
    enabled: true
    radius: 0.8

  cropbox:
    enabled: true
```

## 6. Benchmark Interface

Each pipeline execution should provide:

```
input_points
output_points
removed_points
removed_ratio
processing_time_ms
```

Purpose:

Allow comparison between:

- raw cloud
- blind filtering
- crop filtering
- angular filtering
- combined filtering

## 7. Integration Boundary

Downstream systems only depend on:

```
filtered PointCloud2 topic
```

They should not know:

- MID360
- filter implementation
- configuration details

This keeps LiDAR preprocessing independent from SLAM and navigation.
