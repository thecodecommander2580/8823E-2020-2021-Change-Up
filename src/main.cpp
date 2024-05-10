/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jaydenliffick                                             */
/*    Created:      Fri Dec 11 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Ball_Senser          limit         D               
// Light                light         A               
// Flash_Light1         motor29       B               
// Flash_Light2         motor29       C               
// Right_Intake         motor         9               
// Left_Intake          motor         21              
// Chamber              motor         7               
// Upper_Chamber        motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
 
#include "vex.h"
 
using namespace vex;
 
void Flash_Light_On ()
{
 Flash_Light1.spin(forward);
 Flash_Light2.spin(forward);
}
 
void Flash_Light_Off ()
{
 Flash_Light1.stop();
 Flash_Light2.stop();
}
 
 
bool BallOveride = false;
bool DebugMode = true;
bool EnableMotors = false;
 
int Light_Value;
int Light_Value1;
int Light_Value2;
int Light_Value3;
int Blue_Color = 50;
 
 
int main() {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
 Flash_Light1.setVelocity(100, percent);
 Flash_Light2.setVelocity(100, percent);
 
 Right_Intake.setVelocity(100, percent);
 Left_Intake.setVelocity(100, percent);
 Right_Intake.setMaxTorque(100, percent);
 Left_Intake.setMaxTorque(100, percent);

 Chamber.setVelocity(100, percent);
 Chamber.setMaxTorque(100, percent);
 Upper_Chamber.setVelocity(100, percent);
 Upper_Chamber.setMaxTorque(100, percent);

 if(EnableMotors)
 {

  Right_Intake.spin(forward);
  Left_Intake.spin(forward);
  Chamber.spin(forward);
  Upper_Chamber.spin(forward);

 }

 Flash_Light_On();

 while(true)
 {
 
   if(Ball_Senser && !BallOveride)
   {
 
     wait(20, msec);
     Light_Value1 = Light.brightness();
     wait(10, msec);
     Light_Value2 = Light.brightness();
     wait(10, msec);
     Light_Value3 = Light.brightness();
     Light_Value = ((Light_Value1 + Light_Value2 + Light_Value3) / 3);
     BallOveride = true;
 
     if(DebugMode)
     {
 
       Controller1.Screen.clearLine(1);
       Controller1.Screen.setCursor(1,1);
       Controller1.Screen.print("%d", Light_Value);
 
     }
 
     if(Light_Value <= Blue_Color)
     {
 
     }
   }
 
   if(!Ball_Senser && BallOveride)
   { BallOveride = false; }
 
   wait(20, msec);
 
 }
}
 

