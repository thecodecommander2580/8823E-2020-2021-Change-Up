/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\User                                             */
/*    Created:      Sat Nov 07 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBackBase         motor         1               
// RightBackBase        motor         2               
// LeftFrontBase        motor         3               
// RightFrontBase       motor         4               
// Inertial             inertial      5               
// Controller1          controller                    
// Shooter              motor         6               
// Chamber              motor         7               
// RightIntake          motor         9               
// LeftIntake           motor         21              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

float Chamber_Speed = 100;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

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
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  LeftFrontBase.setVelocity(100, percent);
  LeftBackBase.setVelocity(100, percent);
  RightFrontBase.setVelocity(100, percent);
  RightBackBase.setVelocity(100, percent);
  LeftFrontBase.setStopping(brake);
  LeftBackBase.setStopping(brake);
  RightFrontBase.setStopping(brake);
  RightBackBase.setStopping(brake);
  LeftIntake.setVelocity(100, percent);
  RightIntake.setVelocity(100, percent);
  LeftIntake.setStopping(brake);
  RightIntake.setStopping(brake);
  Chamber.setVelocity(Chamber_Speed, percent);
  Chamber.setStopping(hold);
  Shooter.setVelocity(100, percent);
  Shooter.setStopping(coast);
  LeftFrontBase.spin(forward);
  LeftBackBase.spin(forward);
  RightFrontBase.spin(forward);
  RightBackBase.spin(forward);
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
  LeftFrontBase.setVelocity(0, percent);
  LeftBackBase.setVelocity(0, percent);
  RightFrontBase.setVelocity(0, percent);
  RightBackBase.setVelocity(0, percent);
  Shooter.spin(forward);
  wait(1, seconds);
  Shooter.stop();

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
  LeftFrontBase.setVelocity(Controller1.Axis3.position(percent), percent);
  LeftBackBase.setVelocity(Controller1.Axis3.position(percent), percent);
  RightFrontBase.setVelocity(Controller1.Axis2.position(percent), percent);
  RightBackBase.setVelocity(Controller1.Axis2.position(percent), percent);
 
  if(Controller1.ButtonR1.pressing())
  {
    LeftIntake.spin(forward);
    RightIntake.spin(forward);
    Chamber.spin(forward);
  }
  else if(Controller1.ButtonR2.pressing())
  {
    LeftIntake.spin(reverse);
    RightIntake.spin(reverse);
    Chamber.spin(reverse);
    Shooter.spin(reverse);
  }
 
  else if(Controller1.ButtonL1.pressing() || Controller1.ButtonL2.pressing() || Controller1.ButtonUp.pressing() || Controller1.ButtonDown.pressing() || Controller1.ButtonX.pressing()) {}
 
  else
  {
    LeftIntake.stop();
    RightIntake.stop();
    Chamber.stop();
    Shooter.stop();
  }

  if(Controller1.ButtonUp.pressing() /* || Controller1.ButtonDown.pressing()*/ ) // Include this code if you really want both buttons to do the same thing
  {
    Chamber.spin(forward);
    Shooter.spin(forward);
  }
  /* if(Controller1.ButtonDown.pressing()) This code does the exact same thing. Including it will also cause problems with the motors not stopping when you press the up button.
  {
    Chamber.spin(forward);
    Shooter.spin(forward);
  }
  */
  else if(Controller1.ButtonL1/*ButtonDown*/.pressing())
  {

    LeftIntake.spin(forward);
    RightIntake.spin(forward);
    Chamber.spin(forward);
    Shooter.spin(forward);
  }
 
  else if(Controller1.ButtonR1.pressing() || Controller1.ButtonR2.pressing() || Controller1.ButtonL2.pressing() || Controller1.ButtonDown.pressing() || Controller1.ButtonX.pressing()) {}
 
  else
  {
    LeftIntake.stop();
    RightIntake.stop();
    Chamber.stop();
    Shooter.stop();
  }
 
  if(Controller1.ButtonL2.pressing())
  {
    LeftIntake.spin(forward);
    RightIntake.spin(forward);
  }
 
  else if(Controller1.ButtonR1.pressing() || Controller1.ButtonR2.pressing() || Controller1.ButtonL1.pressing() || Controller1.ButtonX.pressing() || Controller1.ButtonUp.pressing() || Controller1.ButtonDown.pressing()) {}
 
  else
  {
  Shooter.stop();
  }

  wait(20, msec); 

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
