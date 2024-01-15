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
  // this part takes so long when testing that i will just use a 3-second portion instead
  // Flywheel.spin(reverse);
  // wait(30, sec);
  // Flywheel.stop();
  Flywheel.spin(reverse);
  wait(40, sec);
  Flywheel.stop();
  // drive to the other side and ram the goal
  drivePID(-2800, -1050);
  drivePID(-1500, 1000);
  drivePID(1500, 0);
  drivePID(-1500, 0);
  // turn around, ram the goal from the front with wings
  drivePID(1500, -1500);
  drivePID(0, -2750);
  Wings.set(true);
  drivePID(2500, 0);
  drivePID(-2000, 0);
  // ram it again
  drivePID(2000, 500);
  drivePID(-1500, 0);
  // // go to the other side and ram it with the back
  // drivePID(1500, 750);
  // drivePID(-1000, 1000);
  // drivePID(1000, 0);
  // drivePID(-1000, 0);
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
