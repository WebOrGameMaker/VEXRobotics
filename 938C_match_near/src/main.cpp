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

  // turning 1225 is 90 degrees right, -1225 is 90 degrees left
  // drivePID(drive, turn);

  // drive forward toward the goal
  drivePID(1000, 0);
  // readjust to prevent the next turn from hitting the goal, drive toward the goal again
  drivePID(1550, 150);
  // turn left to the goal
  drivePID(0, -1350);
  // outtake the matchload
  Intake.spin(reverse);
  wait(350, msec);
  Intake.stop();
  // prepare to intake the green triball
  Intake.spin(forward);
  drivePID(1100, 2250);
  wait(100, msec);
  Intake.stop();
  drivePID(500, 2250);
  Intake.spin(reverse);
  wait(450, msec);
  Intake.stop();
  drivePID(0, 2300);
  drivePID(-1250, 0);
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
