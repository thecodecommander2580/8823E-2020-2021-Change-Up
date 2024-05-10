#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftBackBase = motor(PORT17, ratio18_1, true);
motor RightBackBase = motor(PORT18, ratio18_1, false);
motor LeftFrontBase = motor(PORT11, ratio18_1, true);
motor RightFrontBase = motor(PORT6, ratio18_1, false);
inertial Inertial = inertial(PORT8);
motor Shooter = motor(PORT10, ratio6_1, false);
motor Chamber = motor(PORT20, ratio6_1, false);
motor RightIntake = motor(PORT3, ratio6_1, true);
motor LeftIntake = motor(PORT2, ratio6_1, false);
optical Optical = optical(PORT15);

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