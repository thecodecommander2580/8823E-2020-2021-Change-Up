/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\User                                             */
/*    Created:      Tue Mar 16 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// DriveMotor           motor         11              
// TurningMotor         motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
    DriveMotor.setStopping(brake);
    TurningMotor.setStopping(brake);
    DriveMotor.spin(forward);
    TurningMotor.spin(forward);

    while (1==1) {

      DriveMotor.setVelocity(Controller1.Axis3.position(percent), percent);
      TurningMotor.setVelocity(Controller1.Axis1.position(percent)*.4, percent);

      
    }
}
