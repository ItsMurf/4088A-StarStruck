#include "main.h"


void operatorControl() {
	while (1) {
		// --------------Drive-------------
		driveSet(joystickGetAnalog(1, 1), joystickGetAnalog(1, 3)); // Tank drive

		// -------------Claw---------------
		if(joystickGetDigital(1, 6, JOY_DOWN)) // Close
		{
			clawSet(-127);
		}
		else if(joystickGetDigital(1, 6, JOY_UP)) // Open
		{
			clawSet(127);
		}
		else
		{
			clawSet(0);
		}
		// -------------Lift---------------
		if(joystickGetDigital(1, 5, JOY_DOWN)) // Down
		{
			armSet(-127);
		}
		else if(joystickGetDigital(1, 5, JOY_UP)) // Up
		{
			armSet(127);
			if(analogRead(pot_p) > 50) // open claw if arm is high enough to dump
			{
				clawSet(127);
			}
		}
		else
		{
			armSet(0);
		}
		delay(20);
	}
}

void driveSet(int right, int left)
{
	// Right side set to first argument. Left side set to second argument.
		motorSet(frontRight_p, right);
		motorSet(backRight_p, right);
		motorSet(frontLeft_p, left);
		motorSet(backLeft_p, left);
}

void clawSet(int motor)
{
	motorSet(rightClaw_p, motor);
	motorSet(leftClaw_p, -motor);
}

void armSet(int motor)
{
	motorSet(topLeftLift_p, -motor);
	motorSet(bottomLeftLift_p, motor);
	motorSet(topRightLift_p, motor);
	motorSet(bottomRight_p, -motor);
}
