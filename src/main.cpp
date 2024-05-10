/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\User                                             */
/*    Created:      Tue Nov 03 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial             inertial      1               
// LeftMotor            motor         2               
// RightMotor           motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  LeftMotor.setStopping(brake);
  RightMotor.setStopping(brake);

  LeftMotor.setVelocity(75, percent);
  RightMotor.setVelocity(75, percent);

  LeftMotor.spin(forward);
  RightMotor.spin(reverse);

  waitUntil(Inertial.rotation(degrees) > 90);

  LeftMotor.stop();
  RightMotor.stop();
}
