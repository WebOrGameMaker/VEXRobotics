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
#include "../../common/controller.h"
using namespace vex;

competition Competition;

int main() {
  vexcodeInit();

  Competition.drivercontrol(usercontrol);
  
  // prevent main from exiting with an infite loop
  // edit
  while (true) {
    wait(100, msec);
  }
} 
