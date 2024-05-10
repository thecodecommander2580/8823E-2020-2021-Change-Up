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
// LeftFrontBase        motor         11              
// LeftBackBase         motor         17              
// RightFrontBase       motor         6               
// RightBackBase        motor         18              
// LeftIntake           motor         2               
// RightIntake          motor         3               
// Chamber              motor         20              
// Shooter              motor         10              
// Controller1          controller                    
// Inertial             inertial      16              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

float Chamber_Speed = 100;
bool Eject_Override = false;
int Velocity = 0;
const int controllerWait = 20;
const int minPidVelocity = 5;
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
  printf("New Run\n");
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

  Inertial.calibrate();
 
  // Optical.setLight(ledState::on);
  // Optical.setLightPower(100, percent);
}

// no other funtion should change drivetrain velocity
void drive(int32_t leftVelocity, int32_t rightVelocity) {

  if(leftVelocity == 0 & rightVelocity == 0)
  {
    LeftFrontBase.stop();
    LeftBackBase.stop();
    RightBackBase.stop();
    RightFrontBase.stop();
  }

  else
  {
    LeftFrontBase.spin(forward);
    LeftBackBase.spin(forward);
    RightFrontBase.spin(forward);
    RightBackBase.spin(forward);
  }
  
  LeftFrontBase.setVelocity(leftVelocity, percent);
  LeftBackBase.setVelocity(leftVelocity, percent);
  RightFrontBase.setVelocity(rightVelocity, percent);
  RightBackBase.setVelocity(rightVelocity, percent);

}

// it drives about 15.3 inches
void driveStraight(double turns) {
  double turnDegrees = (turns * 360);
  // define tunable pid constants
  LeftFrontBase.setPosition(0, degrees);
  RightFrontBase.setPosition(0, degrees);
  const double Kp = .06;
  //const double Ki = 0.0;
  //const double Kd = 0.0;
  double leftMotorDegrees = 0;
  double rightMotorDegrees = 0;
  double averageDegrees = 0;
  double error = turnDegrees;
  int loopCount = 0;

  printf("Drive Straight\n");
  printf("PreError = %f\n", error);
  printf("PreLeft Motor Degrees = %f\n", leftMotorDegrees);
  printf("PreRight Motor Degrees = %f\n", rightMotorDegrees);
  printf("PreAverageLeft Motor Degrees = %f\n\n", averageDegrees);

  // get Data from sensors, position in degrees
  while (error > 0) {
    
  loopCount = loopCount+1;

    leftMotorDegrees = LeftFrontBase.position(degrees);
    rightMotorDegrees = RightFrontBase.position(degrees);
    averageDegrees = (leftMotorDegrees + rightMotorDegrees) / 2;
    // error
    error = turnDegrees - averageDegrees;

    printf("Error = %f\n", error);
    printf("Left Motor Degrees = %f\n", leftMotorDegrees);
    printf("Right Motor Degrees = %f\n", rightMotorDegrees);
    printf("AverageLeft Motor Degrees = %f\n\n", averageDegrees);


    // calculate p, i and d
    double p = error * Kp;

    // with p, i and d calc velocity in percent
    double straightVelocity = p; // + i + d

    //straight vel cannot be low.
    if(straightVelocity < minPidVelocity){
      straightVelocity = minPidVelocity;
    }
    if (loopCount >= 30) {
      if(LeftFrontBase.velocity(percent) < 5){
      error =0;
    }
     
    }
    // command motors
    drive(straightVelocity, straightVelocity);
    wait(controllerWait, msec);

  }
      drive(0,0);
}


void driveStraightWithCorrection(double turns) {
  double turnDegrees = (turns * 360);
  // define tunable pid constants
  LeftFrontBase.setPosition(0, degrees);
  RightFrontBase.setPosition(0, degrees);
  const double Kp = .06;
  //const double Ki = 0.0;
  //const double Kd = 0.0;
  double leftMotorDegrees = 0;
  double rightMotorDegrees = 0;
  double averageDegrees = 0;
  double errorRight = 0;
  double errorLeft = 0;

 int loopCount = 0;
  // get Data from sensors, position in degrees
  while (errorRight > 0) {
    loopCount = loopCount+1;

    leftMotorDegrees = LeftFrontBase.position(degrees);
    rightMotorDegrees = RightFrontBase.position(degrees);
    averageDegrees = (leftMotorDegrees + rightMotorDegrees) / 2;
    // error
    errorLeft = turnDegrees - LeftFrontBase.position(degrees);
    errorRight = turnDegrees - RightFrontBase.position(degrees);

    // calculate p, i and d
    double pRight = errorRight * Kp;
    double pLeft = errorLeft * Kp;

    // with p, i and d calc velocity in percent
    double straightVelocityRight = pRight;
    double straightVelocityLeft = pLeft; // + i + d

    //straight vel cannot be low.
    if(straightVelocityRight < minPidVelocity){
      straightVelocityRight = minPidVelocity;
    }
    if(straightVelocityLeft < minPidVelocity){
      straightVelocityLeft = minPidVelocity;
    }
    if (loopCount >= 30) {
      if(LeftFrontBase.velocity(percent) < 5){
        errorLeft =0;
        }
    }
    if (loopCount >= 30) {
      if(RightFrontBase.velocity(percent) < 5){
        errorRight =0;
      }
    }
    // command motors
    drive(straightVelocityRight, straightVelocityLeft);
    wait(controllerWait, msec);
    }
  drive(0,0);
} 



void driveBack(double turns) {
  double turnDegrees = (turns * 360);
  // define tunable pid constants
  LeftFrontBase.setPosition(0, degrees);
  RightFrontBase.setPosition(0, degrees);
  const double Kp = .12;//.06
  //const double Ki = 0.0;
  //const double Kd = 0.0;
  double leftMotorDegrees = 0;
  double rightMotorDegrees = 0;
  double averageDegrees = 0;
  double error = turnDegrees;

  // get Data from sensors, position in degrees
  while (error > 0) {
    leftMotorDegrees = LeftFrontBase.position(degrees);
    rightMotorDegrees = RightFrontBase.position(degrees);
    averageDegrees = (leftMotorDegrees + rightMotorDegrees) / -2;
    // error
    error = turnDegrees - averageDegrees;

    // calculate p, i and d
    double p = error * Kp;

    // with p, i and d calc velocity in percent
    double straightVelocity = p; // + i + d

    //straight vel cannot be low.
    if(straightVelocity < minPidVelocity){
      straightVelocity = minPidVelocity;
    }
  
    // command motors
    drive((straightVelocity * -1), (straightVelocity * -1));
    wait(controllerWait, msec);

  }
      drive(0,0);

}


 //turn is 130 degrees
 void rightTurn1(double turns) {
  int turnDegrees = turns * 360;
  // define tunable pid constants
  LeftFrontBase.setPosition(0, degrees);
  RightFrontBase.setPosition(0, degrees);
  double Kp = .06;
  //double Ki = 0.0;
  //double Kd = 0.0;
  int leftMotorDegrees = LeftFrontBase.position(degrees);
  int rightMotorDegrees = RightFrontBase.position(degrees);
  int combinedDegrees = (leftMotorDegrees + rightMotorDegrees) / 2;
  int error = turnDegrees - combinedDegrees;

  // get Data from sensors, position in degrees
  while (error > 0) {
    leftMotorDegrees = LeftFrontBase.position(degrees);
    rightMotorDegrees = RightFrontBase.position(degrees);
    combinedDegrees = (leftMotorDegrees - rightMotorDegrees) / 2;
    // error
    error = turnDegrees - combinedDegrees;

    // calculate p, i and d
    double p = error * Kp;

    // with p, i and d calc velocity in percent
    int turnVelocity = p;

    if (turnVelocity < minPidVelocity) {
      turnVelocity = minPidVelocity;
    }

    // command motors
    drive(turnVelocity, (turnVelocity * -1));
    wait(controllerWait, msec);
 
  }
      drive(0,0);

}

//turn is 130 degrees
void leftTurn1(double turns) {
  int turnDegrees = turns * 360;
  // define tunable pid constants
  LeftFrontBase.setPosition(0, degrees);
  RightFrontBase.setPosition(0, degrees);
  double Kp = .06;
  //double Ki = 0.0;
  //double Kd = 0.0;
 // int leftMotorDegrees = LeftFrontBase.position(degrees);
  //int rightMotorDegrees = RightFrontBase.position(degrees);
  //int combinedDegrees = (leftMotorDegrees + rightMotorDegrees) / 2;
  int error = turnDegrees;

  // get Data from sensors, position in degrees
  while (error > 0) {
    int leftMotorDegrees = LeftFrontBase.position(degrees);
    int rightMotorDegrees = RightFrontBase.position(degrees);
    int combinedDegrees = (rightMotorDegrees - leftMotorDegrees) / 2;
    // error
    error = turnDegrees - combinedDegrees;

    // calculate p, i and d
    double p = error * Kp;

    // with p, i and d calc velocity in percent
    int turnVelocity = p;

    if (turnVelocity < minPidVelocity) {
      turnVelocity = minPidVelocity;
    }

    // command motors
    drive((turnVelocity * -1), turnVelocity);
    wait(controllerWait, msec);
  }
    drive(0,0);

}


void turnleft (double turns)
{
  Inertial.resetRotation();

  double turnDegrees = -turns;
  // define tunable pid constants

  double Kp = .5;
  //double Ki = 0.0;
  //double Kd = 0.0;
  
  double error = turnDegrees;

  printf("Turn Left\n");

  printf("Pre Error = %f\n", error);
  printf("Pre Inertial Rotation = %f\n", Inertial.rotation(degrees));
  printf("Turn Degrees = %f\n\n", turnDegrees);

  // get Data from sensors, position in degrees
  while (error < 0) {
    double inertialDegrees = Inertial.rotation(degrees);
    // error
    error = turnDegrees - inertialDegrees;

    printf("Error = %f\n", error);
    printf("Inertial Rotation = %f\n\n", inertialDegrees);

    // calculate p, i and d
    double p = error * Kp;

    // with p, i and d calc velocity in percent
    double turnVelocity = p;

    if (turnVelocity > -minPidVelocity) {
      turnVelocity = -minPidVelocity;
    }

    // command motors
    drive((turnVelocity), turnVelocity * -1);
    wait(controllerWait, msec);
  }
    drive(0,0);

}

void turnright (double turnDegrees)
{
  Inertial.resetRotation(); 

  // define tunable pid constants
  double Kp = .5;
  //double Ki = 0.0;
  //double Kd = 0.0;
  //int leftMotorDegrees = LeftFrontBase.position(degrees);
  //int rightMotorDegrees = RightFrontBase.position(degrees);
  //int combinedDegrees = (leftMotorDegrees + rightMotorDegrees) / 2;
  double error = turnDegrees;

  printf("Turn Right\n");

  //score a really big score so we can actually go to state, maybe? Also issue a kill order on Gram Clifton. ASAP.
  //No kill order will be issued by me against Gram Clifton. Autonomus will be worked on.

  // get Data from sensors, position in degrees
  
  printf("Turn Degrees = %f\n\n", turnDegrees);
  printf("Pre Error = %f\n", error);
  printf("Pre Inertial Rotation = %f\n\n", Inertial.rotation(degrees));
  

  while (error > 0) {
    double inertialDegrees = Inertial.rotation(degrees);
    
    // error
    error = turnDegrees - inertialDegrees;

    printf("Error = %f\n", error);
    printf("Inertial Rotation = %f\n\n", inertialDegrees);

    // calculate p, i and d
    double p = error * Kp;

    // with p, i and d calc velocity in percent
    double turnVelocity = p;

    if (turnVelocity < minPidVelocity) {
      turnVelocity = minPidVelocity;
    }

    // command motors
    drive((turnVelocity), turnVelocity* -1);
    wait(controllerWait, msec);
  }
    drive(0,0);

}



// drive(leftVelocity, rightVelocity);


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
  //Configure Everything

  LeftFrontBase.setVelocity(0, percent);
  LeftBackBase.setVelocity(0, percent);
  RightFrontBase.setVelocity(0, percent);
  RightBackBase.setVelocity(0, percent);
  LeftBackBase.setStopping(brake);
  LeftFrontBase.setStopping(brake);
  RightBackBase.setStopping(brake);
  RightFrontBase.setStopping(brake);

  ///*
  //Score First Ball
  Shooter.spin(forward);
  wait(.3, seconds);
  Shooter.stop();

  waitUntil(!Inertial.isCalibrating());

  //Get Second Ball
  // driveStraight (1);
  LeftIntake.spin(forward);
  RightIntake.spin(forward);
  Chamber.spin(forward);
  driveStraight(1);
  Chamber.stop();

  //Score Second Ball and Descore First Blue Ball
  turnright(13);
  driveStraight(2.5);
  LeftIntake.stop();
  RightIntake.stop();
  turnright(84);
   LeftIntake.spin(forward);
  RightIntake.spin(forward);
  driveStraight(1);
  //Chamber.spin(reverse);
  //Shooter.spin(reverse);
  //wait(.8, seconds);//1
  //Shooter.stop();
  //Chamber.stop();
 
  //1
  Chamber.spin(forward);
  Shooter.spin(forward);
  wait(0.55, seconds);//1
  Shooter.stop();
  Chamber.stop();
  LeftIntake.stop();
  RightIntake.stop();
 // LeftIntake.spin(forward);
 // RightIntake.spin(forward);
  //wait(.4, seconds);   
  //LeftIntake.stop();
  //RightIntake.stop();

  //Get Third Ball and Eject First Blue Ball
  //driveStraight(1);
  driveBack(.45);

  //*/

 /*
  //Score First Ball
  Shooter.spin(forward);
  wait(.3, seconds);
  Shooter.stop();

  waitUntil(!Inertial.isCalibrating());

  //Get Second Ball
  // driveStraight (1);
  LeftIntake.spin(forward);
  RightIntake.spin(forward);
  Chamber.spin(forward);
  driveStraight(1);
  Chamber.stop();

  //Score Second Ball and Descore First Blue Ball
  rightTurn(.125); //60 Degrees
  driveStraight(2.3);
  LeftIntake.stop();
  RightIntake.stop();
  rightTurn(.5);
  driveStraight(.7);
  Chamber.spin(reverse);
  Shooter.spin(reverse);
  wait(1, seconds);
  Shooter.stop();
  Chamber.stop();
  wait(1, seconds);
  Chamber.spin(forward);
  Shooter.spin(forward);
  wait(1, seconds);
  Shooter.stop();
  Chamber.stop();
  LeftIntake.spin(forward);
  RightIntake.spin(forward);
  wait(.5, seconds);   
  LeftIntake.stop();
  RightIntake.stop();

  //Get Third Ball and Eject First Blue Ball
  //driveStraight(1);
  driveBack(.7);
  LeftIntake.spin(reverse);
  RightIntake.spin(reverse);
  wait(0.8, seconds);
  LeftIntake.stop();
  RightIntake.stop();
  leftTurn(.45);
  LeftIntake.spin(forward);
  RightIntake.spin(forward);
  driveStraight(1);
  LeftIntake.spin(forward);
  RightIntake.spin(forward);
  driveStraight(1.9);
  LeftIntake.stop();
  RightIntake.stop();

  //Score Third Ball
  rightTurn(0.15);
  driveStraight(1.5);
  Chamber.spin(forward);
  Shooter.spin(forward);
  wait(1, seconds);
  Chamber.stop();
  Shooter.stop();
  driveBack(0.3);
  leftTurn(.6);
  LeftIntake.spin(forward); 
  RightIntake.spin(forward);
  driveStraight(2);
  LeftIntake.stop();
  RightIntake.stop();
  leftTurn(.2);
  driveStraight(2);
  Chamber.spin(forward);
  Shooter.spin(forward);
  wait(3, seconds);
  Chamber.stop();
  Shooter.stop();
  driveBack(1);
  leftTurn(1);
  */


}

int calculateLeftVelocityGoal(int axis3, int axis1) {
  int goal = axis3 + axis1;
  return goal;
}
int32_t calculateRighttVelocityGoal(int32_t axis3, int32_t axis1) {
  return axis3 - axis1;
}

// loopcount = loops we've  been accelerating to this goal, it resets when we
// reach goal
int calculateDampenedVelocity_Expon_Scheme1(int goal, int curVelocity,
int loopCount) {
  int exponential = loopCount * loopCount;
  if (curVelocity < goal) {
    int suggestedVelocity = curVelocity + exponential;
    // check overshoot
    if (suggestedVelocity < goal)
      return suggestedVelocity;
    // prevent overshot with correction
    return goal;
  }
  if (curVelocity > goal) {
    int suggestedVelocity = curVelocity - exponential;
    // check overshoot
    if (suggestedVelocity > goal)
      return suggestedVelocity;
    // prevent overshot with correction
    return goal;
  }
  // else velocity must equal goal
  return curVelocity;
}

int calculateDampenedVelocity_Linear_Scheme2(int goal, int curVelocity) {
  int increment = 10;
  if (curVelocity < goal) {
    int suggestedVelocity = curVelocity + increment;
    // check overshoot
    if (suggestedVelocity < goal)
      return suggestedVelocity;
    // prevent overshot with correction
    return goal;
  }
  if (curVelocity > goal) {
    int suggestedVelocity = curVelocity - increment;
    // check overshoot
    if (suggestedVelocity > goal)
      return suggestedVelocity;
    // prevent overshot with correction
    return goal;
  }
  // else velocity must equal goal
  return curVelocity;
}

int calculateDampenedVelocity_Proportional_Scheme3(int goal, int curVelocity) {

  if (curVelocity < goal) {
    return curVelocity + ((goal - curVelocity) / 2);
  }
  if (curVelocity > goal) {
    return curVelocity - ((goal - curVelocity) / 2);
  }
  return curVelocity;
}

int calculateDampenedVelocity(int scheme, int goal, int curVelocity,
                              int loopCount) {
  if (scheme == 1)
    return calculateDampenedVelocity_Expon_Scheme1(goal, curVelocity,
                                                   loopCount);
  if (scheme == 2)
    return calculateDampenedVelocity_Linear_Scheme2(goal, curVelocity);
  // else
  return calculateDampenedVelocity_Proportional_Scheme3(goal, curVelocity);
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
  while (1==1) {

  LeftFrontBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent)*.55, percent);
  LeftBackBase.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent)*.55, percent);
  RightFrontBase.setVelocity(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent)*.55, percent);
  RightBackBase.setVelocity(Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent)*.55, percent);
 
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
    Shooter.spin(reverse);
  }
  else if (Controller1.ButtonL1.pressing()) 
  {
    LeftIntake.spin(forward);
    RightIntake.spin(forward);
    Chamber.spin(forward);
  }
  else if (Controller1.ButtonL2.pressing()) 
  {
    LeftIntake.spin(reverse);
    RightIntake.spin(reverse);
    Chamber.spin(reverse);
  }
  else if (Controller1.ButtonX.pressing())
  {
    Chamber.spin(forward);
    Shooter.spin(forward);
  }
  else if (Controller1.ButtonA.pressing())
  {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("L-F ");
    Controller1.Screen.print(LeftFrontBase.temperature());  
    Controller1.Screen.print("    L-B ");
    Controller1.Screen.print(LeftBackBase.temperature());
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print("R-F ");
    Controller1.Screen.print(RightFrontBase.temperature());  
    Controller1.Screen.print("    R-B ");
    Controller1.Screen.print(RightBackBase.temperature());
  }
  else if (Controller1.ButtonY.pressing())
  {
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("L-I ");
    Controller1.Screen.print(LeftIntake.temperature());  
    Controller1.Screen.print("    R-I ");
    Controller1.Screen.print(RightIntake.temperature());
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print("B-R ");
    Controller1.Screen.print(Chamber.temperature());  
    Controller1.Screen.print("   T-R ");
    Controller1.Screen.print(Shooter.temperature());
  }
  
  else
  {
    LeftIntake.stop();
    RightIntake.stop();
    Chamber.stop();
    Shooter.stop();
  }

}
}
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
