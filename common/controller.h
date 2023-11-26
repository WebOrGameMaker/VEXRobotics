#include <vex.h>
#include "functions.h"

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