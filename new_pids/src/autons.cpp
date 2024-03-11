#include "vex.h"

void match_near() {
  // Match Near
  Intake.setVelocity(300, pct);
  Cata.setVelocity(60, pct);
  Intake.spin(forward);
  wait(300, msec);
  Intake.stop();
  chassis.drive_with_voltage(-5.75, -10);
  wait(1150, msec);
  chassis.drive_with_voltage(3.5, 10);
  wait(250, msec);
  BackWings.set(true);
  wait(250, msec);
  chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  BackWings.set(false);
  chassis.turn_to_angle(-45);
  Intake.spin(forward);
  chassis.drive_with_voltage(9, 9);
  wait(625, msec);
  chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);

  // Match Far
  // setting stuff up
  // Intake.setVelocity(300, pct);
  // Cata.setVelocity(50, pct);
  // Intake.spin(forward);
  // wait(200, msec);
  // Intake.stop();
  // // getting the triball under the bar
  // Intake.spin(reverse);
  // wait(500, msec);
  // // scoring alliance triball, getting ball o
  // chassis.drive_distance(-25, 0, 15, 9, 1, 100, 500);
  // BackWings.set(true);
  // chassis.drive_with_voltage(-10, -4);
  // wait(625, msec);
  // BackWings.set(false);
  // wait(375, msec);
  // chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  // chassis.drive_with_voltage(9, 9);
  // wait(300, msec);
  // chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  // chassis.turn_to_angle(90, 9);
  // Intake.spin(forward);
  // chassis.drive_with_voltage(15, 15);
  // wait(750, msec);
  // chassis.drive_with_voltage(-9, -9);
  // wait(300, msec);
  // chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  // chassis.turn_to_angle(270, 9);
  // chassis.drive_with_voltage(-9, -9);
  // wait(400, msec);
  // chassis.drive_with_voltage(9, 9);
  // wait(250, msec);
  // chassis.turn_to_angle(25, 9);
  // Intake.spin(reverse);

  // chassis.drive_with_voltage(9, 9);
  // wait(1000, msec);
  // chassis.turn_to_angle(140, 9);
  // Intake.spin(forward);
  // wait(300, msec);
  // chassis.turn_to_angle(70, 9);
  // Intake.spin(reverse);
  // chassis.drive_with_voltage(9, 9);
  // wait(200, msec);
  // chassis.turn_to_angle(180, 9);
  // FrontWings.set(true);
  // chassis.drive_with_voltage(9, 9);

  // // Skills Auton
  // Intake.setVelocity(300, pct);
  // Cata.setVelocity(60, pct);
  // chassis.turn_to_angle(45, 9);
  // chassis.drive_with_voltage(-11, -8);
  // wait(700, msec);
  // chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  // chassis.drive_with_voltage(9, 7);
  // wait(300, msec);
  // chassis.turn_to_angle(100, 9);
  // chassis.drive_with_voltage(-9, -9);
  // wait(150, msec);
  // chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  // BackWings.set(true);
  // Cata.spin(reverse);
  // wait(31.5, sec);
  // Cata.stop();
  // BackWings.set(false);
  // chassis.set_heading(100);
  // chassis.turn_to_angle(30, 9);
  // chassis.drive_with_voltage(9, 9);
  // wait(375, msec);
  // chassis.turn_to_angle(82.5, 9);
  // chassis.drive_with_voltage(9, 9);
  // wait(1400, msec);
  // chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);

  // chassis.turn_to_angle(-90);
  // chassis.drive_with_voltage(-5, -10);
  // wait(1400, msec);
  // chassis.drive_with_voltage(9, 9);
  // wait(350, msec);
  // chassis.drive_with_voltage(-9, -9);
  // wait(600, msec);
  // chassis.drive_with_voltage(9, 9);
  // wait(150, msec);

  // chassis.turn_to_angle(90);
  // chassis.drive_with_voltage(-7, -3);
  // wait(1500, msec);
  // chassis.drive_distance(0, 0, 0, 0, 0.1, 100, 500);
  // chassis.turn_to_angle(-65, 5);
  // BackWings.set(true);
  // chassis.drive_with_voltage(-10, -10);
  // wait(650, msec);
  // BackWings.set(false);
  // chassis.turn_to_angle(-100);
  // chassis.drive_with_voltage(6, 6);
  // wait(1000, msec);
  // chassis.drive_distance(0, 0, 0, 0, 0.1, 100, 500);
  // BackWings.set(true);
  // chassis.turn_to_angle(-70);
  // chassis.drive_with_voltage(-10, -10);
  // wait(750, msec);
  // BackWings.set(false);
  // chassis.turn_to_angle(-90);
  // chassis.drive_with_voltage(6, 6);
  // wait(1000, msec);
  // chassis.drive_distance(0, 0, 0, 0, 0.1, 100, 500);
  // chassis.turn_to_angle(-70);
  // BackWings.set(true);
  // chassis.drive_with_voltage(-10, -10);
}

void match_far() {
  // Match Far
  // setting stuff up
  Intake.setVelocity(300, pct);
  Cata.setVelocity(50, pct);
  Intake.spin(forward);
  wait(200, msec);
  Intake.stop();
  // getting the triball under the bar
  Intake.spin(reverse);
  wait(500, msec);
  // scoring alliance triball, getting ball out
  chassis.drive_distance(-25, 0, 15, 9, 1, 100, 500);
  BackWings.set(true);
  chassis.drive_with_voltage(-10, -4);
  wait(625, msec);
  BackWings.set(false);
  wait(375, msec);
  chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  chassis.drive_with_voltage(9, 9);
  wait(300, msec);
  chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  chassis.turn_to_angle(90, 9);
  Intake.spin(forward);
  chassis.drive_with_voltage(15, 15);
  wait(750, msec);
  chassis.drive_with_voltage(-9, -9);
  wait(300, msec);
  chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  chassis.turn_to_angle(270, 9);
  chassis.drive_with_voltage(-9, -9);
  wait(400, msec);
  chassis.drive_with_voltage(9, 9);
  wait(250, msec);
  chassis.turn_to_angle(25, 9);
  Intake.spin(reverse);

  chassis.drive_distance(9, 9);
  wait(1000, msec);
  chassis.turn_to_angle(140, 9);
  Intake.spin(forward);
  wait(300, msec);
  chassis.turn_to_angle(70, 9);
  Intake.spin(reverse);
  chassis.drive_with_voltage(9, 9);
  wait(200, msec);
  chassis.turn_to_angle(180, 9);
  FrontWings.set(true);
  chassis.drive_with_voltage(9, 9);
}

void programming_skills() {
  // Skills Auton
  Intake.setVelocity(300, pct);
  Cata.setVelocity(60, pct);
  chassis.turn_to_angle(45, 9);
  chassis.drive_with_voltage(-11, -8);
  wait(700, msec);
  chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  chassis.drive_with_voltage(9, 7);
  wait(300, msec);
  chassis.turn_to_angle(100, 9);
  chassis.drive_with_voltage(-9, -9);
  wait(150, msec);
  chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);
  BackWings.set(true);
  Cata.spin(reverse);
  wait(31.5, sec);
  Cata.stop();
  BackWings.set(false);
  chassis.set_heading(100);
  chassis.turn_to_angle(30, 9);
  chassis.drive_with_voltage(9, 9);
  wait(375, msec);
  chassis.turn_to_angle(82.5, 9);
  chassis.drive_with_voltage(9, 9);
  wait(1400, msec);
  chassis.drive_distance(0, 0, 0, 0, 1, 100, 500);

  chassis.turn_to_angle(-90);
  chassis.drive_with_voltage(-5, -10);
  wait(1400, msec);
  chassis.drive_with_voltage(9, 9);
  wait(350, msec);
  chassis.drive_with_voltage(-9, -9);
  wait(600, msec);
  chassis.drive_with_voltage(9, 9);
  wait(150, msec);

  chassis.turn_to_angle(90);
  chassis.drive_with_voltage(-7, -3);
  wait(1500, msec);
  chassis.drive_distance(0, 0, 0, 0, 0.1, 100, 500);
  chassis.turn_to_angle(-65, 5);
  BackWings.set(true);
  chassis.drive_with_voltage(-10, -10);
  wait(650, msec);
  BackWings.set(false);
  chassis.turn_to_angle(-100);
  chassis.drive_with_voltage(6, 6);
  wait(1000, msec);
  chassis.drive_distance(0, 0, 0, 0, 0.1, 100, 500);
  BackWings.set(true);
  chassis.turn_to_angle(-70);
  chassis.drive_with_voltage(-10, -10);
  wait(750, msec);
  BackWings.set(false);
  chassis.turn_to_angle(-90);
  chassis.drive_with_voltage(6, 6);
  wait(1000, msec);
  chassis.drive_distance(0, 0, 0, 0, 0.1, 100, 500);
  chassis.turn_to_angle(-70);
  BackWings.set(true);
  chassis.drive_with_voltage(-10, -10);
}

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}