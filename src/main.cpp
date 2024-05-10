/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\User                                             */
/*    Created:      Tue Dec 08 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1               motor         1               
// MotorA               motor29       A               
// ServoB               servo         B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Motor1.setMaxTorque(100, percent);
  Motor1.setVelocity(100, percent);
  Motor1.setStopping(brake);

  MotorA.setVelocity(100, percent);
  
  Motor1.spin(forward);
  MotorA.spin(forward);

  while(true)
  {

    ServoB.setPosition(-50, degrees);
    wait(1, seconds);
    ServoB.setPosition(50, degrees);
    wait(1, seconds);

  }

}
