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

#include "vex.h"
#include <functions.h>

using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void auton() {
  vexcodeInit();
  InertialSensor.calibrate();

  // open intake pistons
  IntakePistons.set(true);
  // open wings
  Wings.set(true);
  // drive forward 20 cm
  drivetrainPID(200, 450);
  // turn left 45 degrees
  // drive forward 20 cm
  drivetrainPID(200, 0);
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

void usercontrol(void) {
  start();

  while (1) {
    LF.spin(fwd, Controller1.Axis3.value() + Controller1.Axis4.value(), pct);
    RF.spin(fwd, Controller1.Axis3.value() - Controller1.Axis4.value(), pct);

    LM.spin(fwd, Controller1.Axis3.value() + Controller1.Axis4.value(), pct);
    RM.spin(fwd, Controller1.Axis3.value() - Controller1.Axis4.value(), pct);

    LB.spin(fwd, Controller1.Axis3.value() + Controller1.Axis4.value(), pct);
    RB.spin(fwd, Controller1.Axis3.value() - Controller1.Axis4.value(), pct);
    
    if (Controller1.ButtonA.pressing()) Wings.set(true);
    else if (Controller1.ButtonB.pressing()) Wings.set(false);
    
    if (Controller1.ButtonLeft.pressing()) IntakePistons.set(true);
    else if (Controller1.ButtonRight.pressing()) IntakePistons.set(false);

    wait(5, msec);
  }
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
