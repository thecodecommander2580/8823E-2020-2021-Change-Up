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
// LeftBackBase         motor         17              
// RightBackBase        motor         16              
// LeftFrontBase        motor         11              
// RightFrontBase       motor         6               
// Inertial             inertial      15              
// Shooter              motor         10              
// Chamber              motor         20              
// RightIntake          motor         3               
// LeftIntake           motor         2               
// Optical              optical       8               
// BallDetection        limit         A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

float Chamber_Speed = 100;
bool Eject_Override = true;
int Ball_Ejection_Goal = 20;
int Ball_Ejection_Timer = 0;

//Autonomus Functions

void Forward (int speed)
{

  LeftFrontBase.setVelocity(speed, percent);
  LeftBackBase.setVelocity(speed, percent);
  RightFrontBase.setVelocity(speed, percent);
  RightBackBase.setVelocity(speed, percent);

}

void Backwards (int speed)
{

  LeftFrontBase.setVelocity(-speed, percent);
  LeftBackBase.setVelocity(-speed, percent);
  RightFrontBase.setVelocity(-speed, percent);
  RightBackBase.setVelocity(-speed, percent);

}

void Stop ()
{

  LeftFrontBase.setVelocity(0, percent);
  LeftBackBase.setVelocity(0, percent);
  RightFrontBase.setVelocity(0, percent);
  RightBackBase.setVelocity(0, percent);

}

void Constant_Left (int speed)
{

  LeftFrontBase.setVelocity(speed, percent);
  LeftBackBase.setVelocity(speed, percent);
  RightFrontBase.setVelocity(-speed, percent);
  RightBackBase.setVelocity(-speed, percent);

}

void Constant_Right (int speed)
{
  LeftFrontBase.setVelocity(-speed, percent);
  LeftBackBase.setVelocity(-speed, percent);
  RightFrontBase.setVelocity(speed, percent);
  RightBackBase.setVelocity(speed, percent);
}


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

  //Move out of the way(Only for now.)

  

  /*

  //Left Red

  Forward(100);
  wait(1, sec);
  Stop();
  
  
    

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
    
    if(Eject_Override) { Shooter.spin(forward); }
  }
  else if(Controller1.ButtonR2.pressing())
  {
    LeftIntake.spin(reverse);
    RightIntake.spin(reverse);
    Chamber.spin(reverse);
    
    if(Eject_Override) { Shooter.spin(reverse); }
  }
  else if (Controller1.ButtonL2.pressing())
  {
    LeftIntake.spin(reverse);
    RightIntake.spin(reverse);
    Chamber.spin(reverse);
  }
  else if(Controller1.ButtonL1.pressing())
  {
    LeftIntake.spin(forward);
    RightIntake.spin(forward);
    Chamber.spin(forward);
  }
  else if (Controller1.ButtonY.pressing())
  {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print(Optical.color());
    wait(50, msec);
  }

  else if(Controller1.ButtonL1.pressing() || Controller1.ButtonL2.pressing() || Controller1.ButtonUp.pressing() || Controller1.ButtonDown.pressing() || Controller1.ButtonX.pressing()) {}
 
  else
  {
    LeftIntake.stop();
    RightIntake.stop();
    Chamber.stop();

    if(Eject_Override){ Shooter.stop(); }
    
  }

  

  if(true)
  {

    if(Optical.color() == blue && Ball_Ejection_Timer == 0) { Eject_Override = true; } //Eject_Override is somewhat backwards. it being true means that the driver has full control of the Shooter.

    else if(16710192 < Optical.color() && Optical.color() < 16721680)
    {

      Eject_Override = false;

      Shooter.spin(reverse);

      Ball_Ejection_Timer = Ball_Ejection_Goal;
      
    }

    else if(Ball_Ejection_Timer == 0)  { Eject_Override = true; }

  }

  if(Ball_Ejection_Timer == 0) 
  { 
    Eject_Override = true;
  }

  if(Ball_Ejection_Timer >= 1)
  {
    Ball_Ejection_Timer = (Ball_Ejection_Timer -1);
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
