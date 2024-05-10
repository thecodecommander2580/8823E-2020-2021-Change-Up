#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftBackBase = motor(PORT1, ratio18_1, false);
motor RightBackBase = motor(PORT2, ratio18_1, true);
motor LeftFrontBase = motor(PORT8, ratio18_1, false);
motor RightFrontBase = motor(PORT21, ratio18_1, false);
inertial Inertial = inertial(PORT4);
motor Shooter = motor(PORT11, ratio18_1, false);
motor Chamber = motor(PORT9, ratio18_1, false);
motor RightIntake = motor(PORT20, ratio18_1, true);
motor LeftIntake = motor(PORT10, ratio18_1, false);
optical Optical = optical(PORT3);

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