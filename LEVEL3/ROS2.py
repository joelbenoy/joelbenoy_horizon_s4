# ROS2 Distance Publisher and Subscriber

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
import random


# Publishes random distance values
class DistPub(Node):
    def __init__(self):
        super().__init__('dist_pub')
        self.dist_pub = self.create_publisher(Int32, 'distance', 10)
        self.tmr = self.create_timer(1.0, self.send_dist)

    def send_dist(self):
        d = Int32()
        d.data = random.randint(1, 100)
        self.dist_pub.publish(d)
        self.get_logger().info(f'Distance sent: {d.data}')


# Subscribes and prints distance values
class DistSub(Node):
    def __init__(self):
        super().__init__('dist_sub')
        self.sub = self.create_subscription(
            Int32,
            'distance',
            self.cb,
            10)

    def cb(self, msg):
        print(f'Distance got: {msg.data}')


def main(args=None):
    rclpy.init(args=args)
    p = DistPub()
    s = DistSub()
    try:
        while rclpy.ok():
            rclpy.spin_once(p, timeout_sec=0.1)
            rclpy.spin_once(s, timeout_sec=0.1)
    except KeyboardInterrupt:
        pass
    p.destroy_node()
    s.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
