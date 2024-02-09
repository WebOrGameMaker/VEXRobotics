/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\yutan                                            */
/*    Created:      Wed Nov 15 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LF                   motor         2               
// LM                   motor         13              
// LB                   motor         18              
// RF                   motor         1               
// RM                   motor         17              
// RB                   motor         16              
// Flywheel             motor         3               
// Wings                digital_out   B               
// IntakePistons        digital_out   A               
// Intake               motor         8               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
#include <../../common/controller.h>
using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void autonomous() {
  start();
  // start at the same position as match far
  IntakePistons.set(true);
  drivePID(250, 0);
  drivePID(0, -900);
  drivePID(1200, 0);
  drivePID(0, 900);
  drivePID(300, 0);
  Intake.spin(reverse);
  wait(500, msec);
  Intake.stop();
  drivePID(0, 2400);
  drivePID(-650, 0);
  drivePID(1000, 0);
  Wings.set(true);
  drivePID(0, -500);
  drivePID(750, 0);
  drivePID(0, -750);
  drivePID(1450, 0);
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // prevent the main function from exiting with an infinite loop
  while (true) {
    wait(100, msec);
  }
} 
