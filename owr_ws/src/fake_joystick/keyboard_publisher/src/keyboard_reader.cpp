#include <termios.h>
#include <ros/ros.h>
#include "std_msgs/Int32.h"

int getch()
{
  static struct termios oldt, newt;
  tcgetattr( STDIN_FILENO, &oldt);           // save old settings
  newt = oldt;
  newt.c_lflag &= ~(ICANON);                 // disable buffering      
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new setting
  int ch = getchar();                        // read character (non-blocking
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
  return ch;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "keyboard");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<std_msgs::Int32>("/key", 1000);
    ros::Rate loop_rate(10);


    while (ros::ok())
    {
        std_msgs::Int32 c;
        c.data = getch();  
        pub.publish(c);
        ros::spinOnce();
        loop_rate.sleep();
    }
}
