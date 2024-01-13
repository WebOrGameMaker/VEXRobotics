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
  // open intake pistons
  IntakePistons.set(true);
  // put the matchload in the goal
  drivePID(1000, 0);
  drivePID(1350, -100);
  drivePID(-200, 1650);
  // outtake the matchload
  Intake.spin(reverse);
  wait(500, msec);
  Intake.stop();
  // intake the 1st green triball
  Intake.spin(forward);
  drivePID(0, -1700);
  drivePID(400, 0);
  Intake.stop();
  // outtake it
  drivePID(0, 2000);
  Intake.spin(reverse);
  wait(400, msec);
  Intake.stop();
  // intake the 2nd green triball
  Intake.spin(forward);
  drivePID(650, 2000);
  // wait(250, msec);
  Intake.stop();
  // turn around and outtake it
  drivePID(600, -2400);
  Intake.spin(reverse);
  wait(400, msec);
  Intake.stop();
  // turn around and ram it with the back
  drivePID(-1300, 2500);
  drivePID(1000, 0);
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(auton);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // prevent main from exiting with an infinite while loop
  while (true) {
    wait(100, msec);
  }
} 
