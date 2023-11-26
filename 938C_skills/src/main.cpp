#include "vex.h"
#include "functions.h"

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

using namespace vex;

void pre_auton(void) {
  vexcodeInit();

  InertialSensor.calibrate();
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
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  while (true) {
    wait(100, msec);
  }
} 
