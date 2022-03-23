#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "sensor_msgs/Joy.h"

class SubscribeAndPublish
{
    public:
        SubscribeAndPublish()
        {
            pub_ = n_.advertise<sensor_msgs::Joy>("/joy_msg", 1);
            sub_ = n_.subscribe("/key", 1, &SubscribeAndPublish::callback, this);
            
            horizontal.data = 0; vertical.data = 0;
        }

        void callback(const std_msgs::Int32::ConstPtr& input)
        {
            sensor_msgs::Joy joy;
            joy.buttons.clear();
            joy.axes.clear();
            
            if (input->data == 119) // ASCII for 'w'
            {
                vertical.data += 0.1;
            }
            else if (input->data == 115) // ASCII for 's'
            {
                vertical.data -= 0.1;
            }
            else if (input->data == 97) // ASCII for 'a'
            {
                horizontal.data -= 0.1;
            }
            else if (input->data == 100) // ASCII for 'd'
            {
                horizontal.data += 0.1;
            }
            
            // SET A LIMIT
            if (vertical.data > 1) 
            {
                vertical.data = 1;
            }
            else if (vertical.data < -1) {
                vertical.data = -1;
            }
            
            if (horizontal.data > 1) 
            {
                horizontal.data = 1;
            }
            else if (horizontal.data < -1) {
                horizontal.data = -1;
            }
            
            // PUBLISH RESULT
            joy.axes.push_back(horizontal.data);
            joy.axes.push_back(vertical.data);
            
            pub_.publish(joy);
        }

    private:
        ros::NodeHandle n_; 
        ros::Publisher pub_;
        ros::Subscriber sub_;
        
        std_msgs::Float32 horizontal;
        std_msgs::Float32 vertical;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "key_to_joy");

  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}
