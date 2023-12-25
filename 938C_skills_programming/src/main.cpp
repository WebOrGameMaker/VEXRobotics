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
// Wings                digital_out   H               
// IntakePistons        digital_out   G               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include <../../common/functions.h>
using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
}

void auton(void) {
  start();
  // Flywheel.spin(reverse);
  // wait(3, sec);
  // Flywheel.stop();
  // drivePID(-3500, -900);
  // drivePID(-1000, 750);
  // drivePID(1500, 300);
  // drive forward 20 cm
  // drivePID(500, 0);
  // turn right 45 degrees
  // drivePID(0, )
  // drive backward 30 cm
  // turn on flywheel for 25 seconds
  // drive forward 10 cm
  // turn right 90 degrees
  // drive forward 20 cm
  // turn left 60 degrees
  // go forward 50 cm
  // turn left 90 degrees
  // open wings
  // drive forward 50 cm
  // close wings
  // drive back 30 cm
  // turn left 45 degrees
  // drive forward 50 cm
  // turn right 135 degrees
  // open wings
  // drive forward 50 cm
  // close wings
  // drive back 50 cm
  // turn left 15 degrees
  // open wings
  // drive forward 50 cm
  // close wings
  // drive back 50 cm
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(auton);

  // Run the pre-autonomous function.
  pre_auton();

  while (true) {
    wait(100, msec);
  }
} 
