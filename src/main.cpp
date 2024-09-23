/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftFront            motor         1               
// leftMid              motor         2               
// leftBack             motor         3               
// rightFront           motor         4               
// rightMid             motor         5               
// rightBack            motor         6               
// inert                inertial      7               
// rightWheel           rotation      8               
// sideWheel            rotation      9               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

vex::motor_group chassisLeft(leftFront, leftMid, leftBack); 
vex::motor_group chassisRight(rightFront, rightMid, rightBack); 

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // All activities that occur before the competition starts
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  inert.calibrate(); // calibrate inertial sensor
  

  while (inert.isCalibrating()) {
    wait(100, msec);
  }

  // resetting rotation sensors
  rightWheel.resetPosition();
  sideWheel.resetPosition();
  

  

  

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop


  while (1) {
    // This is the main execution loop for the user control program.

    int leftY = Controller1.Axis3.position(percent); // retrieves value from left joystick y axis
    int rightX = Controller1.Axis1.position(percent); //retrieves value from right joystick x axis

    chassisLeft.spin(vex::directionType::fwd, leftY + rightX, velocityUnits(percent));
    chassisRight.spin(vex::directionType::fwd, leftY - rightX, velocityUnits(percent));


    
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
