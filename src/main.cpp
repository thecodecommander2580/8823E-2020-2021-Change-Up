/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                   
// LeftBackBase         motor         1              
// RightBackBase        motor         2              
// LeftFrontBase        motor         8              
// RightFrontBase       motor         21             
// Inertial             inertial      4              
// Shooter              motor         11             
// Chamber              motor         9              
// RightIntake          motor         20             
// LeftIntake           motor         10             
// Optical              optical       3              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

float Chamber_Speed = 100;
bool Eject_Override = false;

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

 Optical.setLight(ledState::on);
 Optical.setLightPower(100, percent);

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

 /*

 //Get first ball

 LeftIntake.spin(forward);
 RightIntake.spin(forward);
  LeftFrontBase.setVelocity(100, percent);
 LeftBackBase.setVelocity(100, percent);
 RightFrontBase.setVelocity(100, percent);
 RightBackBase.setVelocity(100, percent);

 wait(2, seconds);

 LeftIntake.stop();
 RightIntake.stop();
  LeftFrontBase.setVelocity(0, percent);
 LeftBackBase.setVelocity(0, percent);
 RightFrontBase.setVelocity(0, percent);
 RightBackBase.setVelocity(0, percent);

 //Put in Middle Bottom Tower

 LeftFrontBase.setVelocity(100, percent);
 LeftBackBase.setVelocity(100, percent);
 RightFrontBase.setVelocity(100, percent);
 RightBackBase.setVelocity(100, percent);

 LeftFrontBase.spin(forward);
 LeftBackBase.spin(forward);
 RightFrontBase.spin(reverse);
 RightBackBase.spin(reverse);

 wait(1, seconds);

 LeftFrontBase.stop();
 LeftBackBase.stop();
 RightFrontBase.stop();
 RightBackBase.stop();

 wait(50, msec);

 LeftFrontBase.spin(forward);
 LeftBackBase.spin(forward);
 RightFrontBase.spin(forward);
 RightBackBase.spin(forward);

 wait(1, seconds);

 LeftFrontBase.stop();
 LeftBackBase.stop();
 RightFrontBase.stop();
 RightBackBase.stop();

 Chamber.spin(forward);
 Shooter.spin(forward);

 wait(1, seconds);

 Chamber.stop();
 Shooter.stoop();

 //Get second ball

 LeftFrontBase.spin(reverse);
 LeftBackBase.spin(reverse);
 RightFrontBase.spin(forward);
 RightBackBase.spin(forward);

 wait(0.8, seconds);

 LeftFrontBase.stop();
 LeftBackBase.stop();
 RightFrontBase.stop();
 RightBackBase.stop();

 wait(50, msec);

 LeftIntake.spin(forward);
 RightIntake.spin(forward);

 LeftFrontBase.spin(forward);
 LeftBackBase.spin(forward);
 RightFrontBase.spin(forward);
 RightBackBase.spin(forward);

 wait(2, seconds);

 LeftFrontBase.stop();
 LeftBackBase.stop();
 RightFrontBase.stop();
 RightBackBase.stop();

 LeftIntake.stop();
 RightIntake.stop();

 //Put in Bottom right tower

 LeftFrontBase.setVelocity(100, percent);
 LeftBackBase.setVelocity(100, percent);
 RightFrontBase.setVelocity(100, percent);
 RightBackBase.setVelocity(100, percent);

 LeftFrontBase.spin(forward);
 LeftBackBase.spin(forward);
 RightFrontBase.spin(reverse);
 RightBackBase.spin(reverse);

 wait(1, seconds);

 LeftFrontBase.stop();
 LeftBackBase.stop();
 RightFrontBase.stop();
 RightBackBase.stop();

 wait(50, msec);

 LeftFrontBase.spin(forward);
 LeftBackBase.spin(forward);
 RightFrontBase.spin(forward);
 RightBackBase.spin(forward);

 wait(1, seconds);

 LeftFrontBase.stop();
 LeftBackBase.stop();
 RightFrontBase.stop();
 RightBackBase.stop();

 Chamber.spin(forward);
 Shooter.spin(forward);

 wait(1, seconds);

 Chamber.stop();
 Shooter.stoop();

 */

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

 LeftFrontBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent), percent);
 LeftBackBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent), percent);
 RightFrontBase.setVelocity(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent), percent);
 RightBackBase.setVelocity(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent), percent);
 if(Controller1.ButtonR1.pressing())
 {
   LeftIntake.spin(forward);
   RightIntake.spin(forward);
   Chamber.spin(forward);
   Shooter.spin(forward);
 }
 else if(Controller1.ButtonR2.pressing())
 {
   LeftIntake.spin(reverse);
   RightIntake.spin(reverse);
   Chamber.spin(reverse);

   if(!Eject_Override){ Shooter.spin(reverse); }
  
 }
 else if(Controller1.ButtonL1.pressing() || Controller1.ButtonL2.pressing() || Controller1.ButtonUp.pressing() || Controller1.ButtonDown.pressing() || Controller1.ButtonX.pressing()) {}
 else
 {
   LeftIntake.stop();
   RightIntake.stop();
   Chamber.stop();

   if(!Eject_Override){ Shooter.stop(); }
  
 }

 /*

 if(Optical.isNearObject())
 {

   if(Optical.color() == red) { Eject_Override = false; }

   else if(Optical.color() == blue)
   {

     Eject_Override = true;

     Shooter.spin(reverse);

   }

 }

 else
 {

   Eject_Override = false;
  

 }

 */

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

