#include "ros/ros.h"
#include "geometry_msgs/TwistStamped.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Float64.h"

class SubscribeAndPublish
{
    public:
        SubscribeAndPublish()
        {
            pub_ = n_.advertise<geometry_msgs::TwistStamped>("/velocity", 1);
            pub_u1 = n_.advertise<std_msgs::Float64>("/u1/command", 1);
            pub_u2 = n_.advertise<std_msgs::Float64>("/u2/command", 1);

            sub_ = n_.subscribe("/joy_msg", 1, &SubscribeAndPublish::callback, this);
        }

        void callback(const sensor_msgs::Joy::ConstPtr& msg)
        {
            float horizontal = msg->axes[0];
            float vertical = msg->axes[1];
            float max_vel = 4;
    
            geometry_msgs::TwistStamped velocity;
            std_msgs::Float64 u1_vel;
            std_msgs::Float64 u2_vel;

            velocity.twist.linear.x = horizontal*max_vel;
            velocity.twist.linear.y = vertical*max_vel;
            velocity.twist.linear.z = 0;
            
            // FIX MATH ON THE JOINTS
            u1_vel.data = velocity.twist.linear.x;
            u2_vel.data = velocity.twist.linear.x;
            
            pub_.publish(velocity);
            pub_u1.publish(u1_vel);
            pub_u2.publish(u2_vel);
        }

    private:
        ros::NodeHandle n_; 
        ros::Publisher pub_;
        ros::Publisher pub_u1;
        ros::Publisher pub_u2;
        ros::Subscriber sub_;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "joy_to_vel");

  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}
