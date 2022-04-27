#include "ros/ros.h"
#include "geometry_msgs/Point.h"


int main(int argc, char **argv){

ros::init(argc, argv, "drone_talker");
ros::NodeHandle n;

ros::Publisher pub = n.advertise<geometry_msgs::Point>("drone_pos", 1000);

float freq = 1;

n.getParam("/dronefreq", freq);


ros::Rate loop_rate(freq);
geometry_msgs::Point pos;

pos.x = 0;
pos.y = 0;
pos.z = 0;

float time = 0.0;

while(ros::ok()){

    if(time == 0.0){
        ROS_INFO("position is : x %f y %f z %f time : %f",pos.x,pos.y,pos.z,time);
        pub.publish(pos);
        time = time + 1/freq;
    }
    else{
        pos.x += 1;
        pos.y -= 1;
        pos.z += 1;
        ROS_INFO("position is : x %f y %f z %f time : %f",pos.x,pos.y,pos.z,time);
        pub.publish(pos);
        time = time + 1/freq;
    }
    
    ros::spinOnce();
    loop_rate.sleep();
}
    return 0;
}