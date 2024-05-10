/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\User                                             */
/*    Created:      Tue Jan 05 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Optical              optical       14              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Optical.setLight(ledState::on);
  Optical.setLightPower(100, percent);

  while(true)
  {

    Brain.Screen.clearScreen();
    Brain.Screen.print("Brightness: %f", Optical.brightness());
    Brain.Screen.setCursor(0,1);
    
    if(Optical.color() == red)
    {
      Brain.Screen.print("Color: Red");
    }

    else if(Optical.color() == blue)
    {
      Brain.Screen.print("Color: Blue");
    }

    else if(Optical.color() == white)
    {
      Brain.Screen.print("Color: White");
    }

    else if (Optical.color() == black)
    {
      Brain.Screen.print("Color: Black");
    }

    else if (Optical.color() == green)
    {
      Brain.Screen.print("Color: Green");
    }

    else if (Optical.color() == yellow)
    {
      Brain.Screen.print("Color: Yellow");
    }

    else if (Optical.color() == orange)
    {
      Brain.Screen.print("Color: Orange");
    }

    else if (Optical.color() == purple)
    {
      Brain.Screen.print("Color: Purple");
    }

    else if (Optical.color() == cyan )
    {
      Brain.Screen.print("Color: Cyan");
    }

    else 
    {
      Brain.Screen.print("Color: Unknown");
    }

    Brain.Screen.setCursor(0, 2);
    Brain.Screen.print("Hue: %d", Optical.hue());


    wait(20, msec);
  }
  
}
