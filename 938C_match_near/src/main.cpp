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
// LF                   motor         5               
// LM                   motor         17              
// LB                   motor         4               
// RF                   motor         19              
// RM                   motor         18              
// RB                   motor         20              
// Intake               motor         13              
// Flywheel             motor         3               
// Controller1          controller                    
// Wings                digital_out   H               
// IntakePistons        digital_out   G               
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
  // open wings
  Wings.set(true);
  // drive forward 20 cm
  // turn left 45 degrees
  drivetrainPID(200, -45);
  // drive forward 20 cm
  drivetrainPID(200, 0);
  // outtake the match load
  Intake.spin(reverse);
  wait(500, msec);
  Intake.stop();
  // retract intake pistons
  IntakePistons.set(false);
  // drive forward 20 cm
  drivetrainPID(200, 0);
  // drive backward 30 cm
  // turn left 60 degrees
  drivetrainPID(-300, -60);
  // turn on intake
  Intake.spin(forward);
  // drive forward 100 cm
  drivetrainPID(1000, 0);
  // stop intake
  Intake.stop();
  // turn right 100 degrees
  drivetrainPID(0, 100);
  // turn on outtake
  Intake.spin(reverse);
  wait(500, msec);
  Intake.stop();
  // turn 180 degrees
  drivetrainPID(0, 180);
  // turn on intake
  Intake.spin(forward);
  // drive forward 40 cm
  drivetrainPID(400, 0);
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
