#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
limit Ball_Senser = limit(Brain.ThreeWirePort.D);
light Light = light(Brain.ThreeWirePort.A);
motor29 Flash_Light1 = motor29(Brain.ThreeWirePort.B, true);
motor29 Flash_Light2 = motor29(Brain.ThreeWirePort.C, true);
motor Right_Intake = motor(PORT9, ratio18_1, true);
motor Left_Intake = motor(PORT21, ratio18_1, false);
motor Chamber = motor(PORT7, ratio18_1, true);
motor Upper_Chamber = motor(PORT8, ratio6_1, false);

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