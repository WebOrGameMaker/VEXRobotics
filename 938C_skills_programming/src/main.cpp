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
  
  // match load for 35 seconds
  Flywheel.spin(reverse);
  wait(35, sec);
  Flywheel.stop();
  // get to the other side
  drivePID(-300, 0);
  drivePID(0, 900);
  drivePID(-600, 0);
  drivePID(0, -250);
  drivePID(-4000, 0);
  //ram the side and adjust to go to the front
  drivePID(0, -800);
  drivePID(-1750, 0);
  drivePID(1150, 0);
  // go to the front, position towards the goal
  drivePID(0, -1150);
  drivePID(-2000, 0);
  drivePID(0, -900);
  // ram once
  Wings.set(true);
  drivePID(2000, 0);
  Wings.set(false);
  // adjust
  drivePID(-1500, 300);
  drivePID(0, -300);
  Wings.set(true);
  drivePID(2500, 300);
  Wings.set(false);
  drivePID(-1500, -300);
  Wings.set(true);
  drivePID(0, -300);
  drivePID(2500, 0);
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
