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
// Intake               motor         8               
// Flywheel             motor         3               
// Controller1          controller                    
// Wings                digital_out   B               
// IntakePistons        digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include <../../common/controller.h>
using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void auton() {
  start();
  // put the matchload in the goal
  drivePID(1000, 0);
  drivePID(1400, -150);
  drivePID(0, 1350);
  // outtake the matchload
  Intake.spin(reverse);
  wait(500, msec);
  Intake.stop();
  // prepare to intake the green triball
  Intake.spin(forward);
  drivePID(800, -1250);
  Intake.stop();
  drivePID(0, 1750);
  Intake.spin(reverse);
  wait(500, msec);
  Intake.stop();
  Intake.spin(forward);
  drivePID(1000, 1250);
  wait(250, msec);
  Intake.stop();
  drivePID(500, -1750);
  Intake.spin(reverse);
  wait(500, msec);
  Intake.stop();
  Wings.set(true);
  drivePID(1250, 0);
  drivePID(-1000, 0);

  // drivePID(800, -1500);
  // Intake.spin(forward);
  // drivePID(1100, -2250);
  // Intake.stop();
  // drivePID(500, -2250);
  // Intake.spin(reverse);
  // wait(450, msec);
  // Intake.stop();
  // drivePID(0, -2300);
  // drivePID(-1250, 0);
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(auton);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  while (true) {
    wait(100, msec);
  }
} 
