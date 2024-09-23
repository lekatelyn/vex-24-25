#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftFront = motor(PORT1, ratio6_1, false);
motor leftMid = motor(PORT2, ratio6_1, false);
motor leftBack = motor(PORT3, ratio6_1, false);
motor rightFront = motor(PORT4, ratio6_1, false);
motor rightMid = motor(PORT5, ratio6_1, false);
motor rightBack = motor(PORT6, ratio6_1, false);
inertial inert = inertial(PORT7);
rotation rightWheel = rotation(PORT8, false);
rotation sideWheel = rotation(PORT9, false);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}