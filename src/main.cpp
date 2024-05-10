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
// Light                light         A               
// Flash_Light1         motor29       B               
// Flash_Light2         motor29       C               
// Ball_Senser          limit         D               
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

int Light_Value;
int Blue_Color = 50;


int main() {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
  Flash_Light1.setVelocity(100, percent);
 Flash_Light2.setVelocity(100, percent);

 while(true)
 {

   if(Ball_Senser && !BallOveride)
   {

     Flash_Light_On();
     wait(90, msec);
     Light_Value = Light.brightness();
     BallOveride = true;
     wait(20, msec);
     Flash_Light_Off();

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

