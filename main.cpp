#include <mbed.h>
#include <ros.h>
#include <std_msgs/Int16.h>
#include "StepMotor.h"

ros::NodeHandle nh;
DigitalOut led(LED3);
StepMotor sm1(PE_13, PE_11, PF_5, PF_4, 0.05);
//StepMotor sm2(PE_9, PD_15, PB_13, PC_4, 0.05);

void stepmotor1_cb(const std_msgs::Int16& cmd_msg) {
	led = 1;
	sm1.setStepGoal(abs(cmd_msg.data), (cmd_msg.data > 0));
}
void stepmotor2_cb(const std_msgs::Int16& cmd_msg) {
//	sm2.setStepGoal(abs(cmd_msg.data), (cmd_msg.data > 0));
}

ros::Subscriber<std_msgs::Int16> subStepMotor1("stepmotor1", stepmotor1_cb);
ros::Subscriber<std_msgs::Int16> subStepMotor2("stepmotor2", stepmotor2_cb);

int main() {
	nh.initNode();
	nh.subscribe(subStepMotor1);
	nh.subscribe(subStepMotor2);
    
    //StepMotor f(PE_13, PE_11, PF_5, PF_4, 1);
//	StepMotor f(LED1, LED2, PF_5, PF_4, 1);
//	f.setStepGoal(10,1);
    
 
    // spin in a main loop. StepMotor will interrupt it to call flip
	while(1) {
		nh.spinOnce();
		wait_ms(1);
	}
}
