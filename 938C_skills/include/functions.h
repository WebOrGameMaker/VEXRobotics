#include "vex.h"
using namespace vex;

competition Competition;

motor_group left_motors(LF, LM, LB);
motor_group right_motors(RF, RM, RB);

inertial InertialSensor(PORT7);

double t_int = 0.0;
double prev_t_err = 0.0;
double t_Kp = 1.0, t_Ki = 0.1, t_Kd = 0.01;

double d_int = 0.0;
double prev_d_err = 0.0;
double d_Kp = 1.0, d_Ki = 0.1, d_Kd = 0.01;

void start() {
  Flywheel.setVelocity(300, percent);
  Intake.setVelocity(150, percent);

  Wings.set(false);
  IntakePistons.set(false);
}

void spin_all(bool left, int val) {
  if (left)
    left_motors.spin(forward, val, voltageUnits::volt);
  else
    right_motors.spin(forward, val, voltageUnits::volt);
}

void stop_all() {
  left_motors.stop();
  right_motors.stop();
}

double secs() { 
  return vex::timer::system() * 0.001; // turn seconds into ms
}

void pause(int ms) { 
  vex::task::sleep(ms); 
}

void pid_turn(double target) {
  while (true) {
    double curr = InertialSensor.rotation(degrees);
    double t_err = target - curr;

    t_int += t_err;

    double t_der = t_err - prev_t_err;
    double t_val = t_Kp * t_err + t_Ki * t_int + t_Kd * t_der;

    prev_t_err = t_err;

    spin_all(true, -t_val);
    spin_all(false, t_val);

    pause(20);

    // if (secs() >= 15) break;
  }
  stop_all();
}

void pid_drive(double target) {
  while (true) {
    double l_enc = LF.rotation(degrees);
    double r_enc = RF.rotation(degrees);

    double d_err = target - (l_enc + r_enc) * 0.5;

    d_int += d_err;

    double d_der = d_err - prev_d_err;
    double d_val = d_Kp * d_err + d_Ki * d_int + d_Kd * d_der;

    prev_d_err = d_err;

    spin_all(true, d_val);
    spin_all(false, d_val);

    pause(20);

    // if (secs() >= 15) break;
  }
  stop_all();
}

void autonomous() {
    vexcodeInit();

    InertialSensor.calibrate();

    return;
}
