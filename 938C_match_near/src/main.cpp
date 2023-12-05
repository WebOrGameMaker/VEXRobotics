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
// Controller1          controller                    
// Wings                digital_out   B               
// IntakePistons        digital_out   A               
// Intake               motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include <../../common/controller.h>
using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void autonomous() {
  start();

  // turning 1225 is 90 degrees right, -1225 is 90 degrees left
  // drivePID(drive, turn);
  IntakePistons.set(true);
  drivePID(1000, 0);
  drivePID(1500, 200);
  drivePID(0, -1225);
  Intake.spin(forward);
  wait(500, msec);
  Intake.stop();
  IntakePistons.set(false);
  drivePID(0, 2500);
  drivePID(-900, 0);
  drivePID(900, 0);
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  while (true) {
    wait(100, msec);
  }
} 
