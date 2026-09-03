from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    config = LaunchConfiguration('config')

    return LaunchDescription([
        DeclareLaunchArgument('config', default_value=''),

        Node(
            package='agt_lidar_filter',
            executable='lidar_filter_node',
            name='agt_lidar_filter_node',
            output='screen',
            parameters=[config]
        )
    ])
