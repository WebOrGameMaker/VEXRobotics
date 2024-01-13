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
  // turn about 45 degrees left
  // drive forward by 1.5 feet
  drivePID(1250, -1300);
  drivePID(-100, 800);
  // outtake the preload
  Intake.spin(reverse);
  wait(400, msec);
  Intake.stop();
  IntakePistons.set(false);
  // turn 180, ram in the triball with the back
  drivePID(-800, 2650);
  // get the corner triball out and touch the bar
  drivePID(1000, 0);
  Wings.set(true);
  drivePID(800, -700);
  drivePID(1600, -700);
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
