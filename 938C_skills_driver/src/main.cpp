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
#include "../../common/controller.h"
using namespace vex;

competition Competition;

int main() {
  vexcodeInit();

  Competition.drivercontrol(usercontrol);

  while (true) {
    wait(100, msec);
  }
} 
