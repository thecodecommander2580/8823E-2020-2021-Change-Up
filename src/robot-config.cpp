#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftBackBase = motor(PORT1, ratio18_1, false);
motor RightBackBase = motor(PORT2, ratio18_1, true);
motor LeftFrontBase = motor(PORT3, ratio18_1, false);
motor RightFrontBase = motor(PORT4, ratio18_1, true);
inertial Inertial = inertial(PORT5);
controller Controller1 = controller(primary);
motor Shooter = motor(PORT6, ratio6_1, false);
motor Chamber = motor(PORT7, ratio18_1, true);
motor RightIntake = motor(PORT9, ratio18_1, true);
motor LeftIntake = motor(PORT21, ratio18_1, false);

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