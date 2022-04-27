#include "ros/ros.h"
#include "geometry_msgs/Point.h"

void chatterCallback(const geometry_msgs::Point::ConstPtr &pos){
    ROS_INFO("I heard : x %f y %f z %f", pos->x, pos->y, pos->z);
}


int main(int argc, char **argv){

    ros::init(argc, argv, "drone_listerner");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("drone_pos", 1000, chatterCallback);
    ros::spin();


    return 0;
}