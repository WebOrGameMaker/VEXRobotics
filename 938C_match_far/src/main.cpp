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
  // open wings
  // drive forward 20 cm
  // turn left 45 degrees
  // drive forward 20 cm
  // outtake the match load
  // retract intake pistons
  // drive forward 20 cm
  // drive backward 30 cm
  // turn left 60 degrees
  // turn on intake
  // drive forward 100 cm
  // stop intake
  // turn right 100 degrees
  // turn on outtake
  // turn 180 degrees
  // turn on intake
  // drive forward 40 cm

  return;
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
