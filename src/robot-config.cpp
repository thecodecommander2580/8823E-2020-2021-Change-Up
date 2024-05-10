#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftFrontBase = motor(PORT11, ratio18_1, true);
motor LeftBackBase = motor(PORT17, ratio18_1, true);
motor RightFrontBase = motor(PORT6, ratio18_1, false);
motor RightBackBase = motor(PORT18, ratio18_1, false);
motor LeftIntake = motor(PORT2, ratio18_1, false);
motor RightIntake = motor(PORT3, ratio18_1, true);
motor Chamber = motor(PORT20, ratio18_1, false);
motor Shooter = motor(PORT10, ratio18_1, false);
controller Controller1 = controller(primary);
inertial Inertial = inertial(PORT16);

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