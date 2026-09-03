#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>

class LidarFilterNode : public rclcpp::Node
{
public:
  LidarFilterNode() : Node("agt_lidar_filter_node")
  {
    input_topic_ = declare_parameter<std::string>("input_topic", "/livox/lidar");
    output_topic_ = declare_parameter<std::string>("output_topic", "/agt/lidar_filtered");

    sub_ = create_subscription<sensor_msgs::msg::PointCloud2>(
      input_topic_, 10,
      std::bind(&LidarFilterNode::callback, this, std::placeholders::_1));

    pub_ = create_publisher<sensor_msgs::msg::PointCloud2>(output_topic_, 10);
  }

private:
  void callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
  {
    // v0.1 skeleton: passthrough only.
    // Filtering plugins will be inserted through PointCloudFilter pipeline.
    pub_->publish(*msg);
  }

  std::string input_topic_;
  std::string output_topic_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr sub_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pub_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LidarFilterNode>());
  rclcpp::shutdown();
  return 0;
}
