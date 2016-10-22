#include "main.h"


/*
 IF FOUND PLEASE CONTACT: (435) 757-8189
 MURF PROS STARSTRUCK V1.0 PROGRAM
 Based on Sammie v4.3
===================================
 Usage:   Drive code for 4088A VEX Robot
 Created: 9/30/16
======================================
 License: Public Domain, use at your own risk.
 */


void pullSet(int control){
	motorSet(6, control);
	motorSet(7, -control);
}
void lDriveSet(int control){
	motorSet(3, control);
	motorSet(2, -control);
}
void rDriveSet(int control){
	motorSet(4, -control);
	motorSet(5, control);
}

void operatorControl() {
	while (true)
	{
		//set drive motors with a dead band of 5
		if(abs(joystickGetAnalog(1,3)) > 5){
			lDriveSet(joystickGetAnalog(1,3));
		}
		else{
			lDriveSet(0);
		}
		if(abs(joystickGetAnalog(1,2)) > 5){
			rDriveSet(joystickGetAnalog(1,2));
		}
		else{
			rDriveSet(0);
		}
		//set pull motor
		if(joystickGetDigital(1, 6, JOY_DOWN)){
			motorSet(6, 127);
		}
		if(joystickGetDigital(1,6, JOY_DOWN)){
			motorSet(7, 127);
		}
	}
}

