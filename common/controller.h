#include <vex.h>
#include "functions.h"

void usercontrol(void) {
  start();

  while (true) {
    // /* slightly higher sens */
    // double left = Controller1.Axis3.value() + Controller1.Axis1.value();
    // double right = Controller1.Axis3.value() - Controller1.Axis1.value();
    // if (left >= 0) left = 1.2 * pow(1.043, left) - 1.2 + 0.2 * left;
    // else {
    //   left = -left;
    //   left = 1.2 * pow(1.043, left) - 1.2 + 0.2 * left;
    //   left = -left;
    // }

    // if (right >= 0) right = 1.2 * pow(1.043, right) - 1.2 + 0.2 * right;
    // else {
    //   right = -right;
    //   right = 1.2 * pow(1.043, right) - 1.2 + 0.2 * right;
    //   right = -right;
    // }
    
    // LF.spin(fwd, left, pct);
    // RF.spin(fwd, right, pct);
    // LM.spin(fwd, left, pct);
    // RM.spin(fwd, right, pct);
    // LB.spin(fwd, left, pct);
    // RB.spin(fwd, right, pct);

    /* slightly higher sens */
    double left = pow(Controller1.Axis3.value() + Controller1.Axis1.value(), 3) / 10000;
    double right = pow(Controller1.Axis3.value() - Controller1.Axis1.value(), 3) / 10000;
    LF.spin(fwd, left, pct);
    RF.spin(fwd, right, pct);
    LM.spin(fwd, left, pct);
    RM.spin(fwd, right, pct);
    LB.spin(fwd, left, pct);
    RB.spin(fwd, right, pct);
    
    if (Controller1.ButtonA.pressing()) Wings.set(true);
    else if (Controller1.ButtonB.pressing()) Wings.set(false);
    
    if (Controller1.ButtonLeft.pressing()) IntakePistons.set(true);
    else if (Controller1.ButtonDown.pressing()) IntakePistons.set(false);
    
    wait(5, msec);
  }
}