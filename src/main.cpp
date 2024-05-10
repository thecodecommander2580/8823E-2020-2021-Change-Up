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
// RightBackBase        motor         18              
// LeftFrontBase        motor         11              
// RightFrontBase       motor         6               
// Inertial             inertial      8               
// Shooter              motor         10              
// Chamber              motor         20              
// RightIntake          motor         3               
// LeftIntake           motor         2               
// Optical              optical       15              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

float Chamber_Speed = 100;
bool Eject_Override = false;
int Acceleration_Speed = 5;

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


  

  //Get first ball



  LeftIntake.spin(forward);
  RightIntake.spin(forward);
  Chamber.spin(forward);
  
  LeftFrontBase.setVelocity(35, percent);
  LeftBackBase.setVelocity(35, percent);
  RightFrontBase.setVelocity(35, percent);
  RightBackBase.setVelocity(35, percent);

  wait(3.7, seconds);

  LeftIntake.stop();
  RightIntake.stop();
  Chamber.stop();
  
  LeftFrontBase.setVelocity(0, percent);
  LeftBackBase.setVelocity(0, percent);
  RightFrontBase.setVelocity(0, percent);
  RightBackBase.setVelocity(0, percent);

  //Put in Middle Bottom Tower

  LeftFrontBase.setVelocity(35, percent);
  LeftBackBase.setVelocity(35, percent);
  RightFrontBase.setVelocity(35, percent);
  RightBackBase.setVelocity(35, percent);

  LeftFrontBase.spin(forward);
  LeftBackBase.spin(forward);
  RightFrontBase.spin(reverse);
  RightBackBase.spin(reverse);


  wait(0.83, seconds);

  LeftFrontBase.stop();
  LeftBackBase.stop();
  RightFrontBase.stop();
  RightBackBase.stop();

  wait(50, msec);

  LeftFrontBase.spin(forward);
  LeftBackBase.spin(forward);
  RightFrontBase.spin(forward);
  RightBackBase.spin(forward);
  LeftIntake.spin(forward);
  RightIntake.spin(forward);

  wait(2.6, seconds);

  LeftFrontBase.stop();
  LeftBackBase.stop();
  RightFrontBase.stop();
  RightBackBase.stop();
  LeftIntake.stop();
  RightIntake.stop();

  Chamber.spin(forward);
  Shooter.spin(forward);

  wait(0.55, seconds);

  Chamber.stop();
  Shooter.stop();

  //Get second ball
  
  LeftFrontBase.spin(reverse);
  LeftBackBase.spin(reverse);
  RightFrontBase.spin(reverse);
  RightBackBase.spin(reverse);

  wait(0.7, seconds);

  LeftIntake.spin(reverse);
  RightIntake.spin(reverse);

  wait(1, seconds);

  LeftIntake.stop();
  RightIntake.stop();


  LeftFrontBase.spin(reverse);
  LeftBackBase.spin(reverse);
  RightFrontBase.spin(forward);
  RightBackBase.spin(forward);

  wait(2.4, seconds);

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

  LeftFrontBase.setVelocity(35, percent);
  LeftBackBase.setVelocity(35, percent);
  RightFrontBase.setVelocity(35, percent);
  RightBackBase.setVelocity(35, percent);

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
  /*
  LeftFrontBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent), percent);
  LeftBackBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent), percent);
  RightFrontBase.setVelocity(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent), percent);
  RightBackBase.setVelocity(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent), percent);
  */

  if(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent) > (LeftFrontBase.velocity(percent) + LeftBackBase.velocity(percent))/2// && abs(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent)) >= Acceleration_Speed)
  )
  {
    LeftFrontBase.setVelocity(LeftFrontBase.velocity(percent) + Acceleration_Speed, percent);
    LeftBackBase.setVelocity(LeftFrontBase.velocity(percent) + Acceleration_Speed, percent);
  }

  else if(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent) < (LeftFrontBase.velocity(percent) + LeftBackBase.velocity(percent))/2// && abs(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent)) >= Acceleration_Speed)
  )
  {
    LeftFrontBase.setVelocity(LeftFrontBase.velocity(percent) - Acceleration_Speed, percent);
    LeftBackBase.setVelocity(LeftFrontBase.velocity(percent) - Acceleration_Speed, percent);
  }
  /*
  else if(abs(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent)) <= Acceleration_Speed)
  {
    LeftFrontBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent), percent);
    RightFrontBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent), percent);
  } 
  */

  if(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent) > (RightBackBase.velocity(percent) + RightFrontBase.velocity(percent))/2// && abs(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent)) >= Acceleration_Speed)
  )
  {
    RightFrontBase.setVelocity(LeftBackBase.velocity(percent) + Acceleration_Speed, percent);
    RightBackBase.setVelocity(LeftBackBase.velocity(percent) + Acceleration_Speed, percent);
  }

  else if(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent) < (RightBackBase.velocity(percent) + RightFrontBase.velocity(percent))/2// && abs(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent)) >= Acceleration_Speed)
  )
  {
    RightFrontBase.setVelocity(LeftBackBase.velocity(percent) - Acceleration_Speed, percent);
    RightBackBase.setVelocity(LeftBackBase.velocity(percent) - Acceleration_Speed, percent);
  }
  /*
  else if(abs(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent)) <= Acceleration_Speed)
  {
    RightFrontBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent), percent);
    RightBackBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent), percent);
  }
  */


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
