#include "vex.h"
#include "drivetrainpid.h"

using namespace vex;

void start() {
  Flywheel.setVelocity(300, percent);
  Intake.setVelocity(150, percent);

  Wings.set(false);
  IntakePistons.set(false);
}

bool toggleDrivePID = 1;

double kP = 0.0078; // proportional
double kI = 0.00007; // integral
double kD = 0.00002; // derivative

double tkP = 0.05; // proportional
double tkI = 0; // integral
double tkD = 0.001; // derivative

double turnConversion = 48/36;

int error; // positive difference between sensor value and desired value (positional)
int prevError; // position of the robot 20 milliseconds ago
int derivative; // error - prevError (speed)
int totalError; // totalError = totalError + error

int turnError; // positive difference between sensor value and desired value (positional)
int turnPrevError; // position of the robot 20 milliseconds ago
int turnDerivative; // error - prevError (speed)
int turnTotalError; // totalError = totalError + error

int marginOfError = 5;

int drivetrainPID(int desiredValue, int desiredTurnValue) {

  desiredTurnValue *= turnConversion;

  int count = 0;

  bool resetDriveSensors = 1;

  while (toggleDrivePID) {
    if (resetDriveSensors) {
      resetDriveSensors = 0;
      LF.setPosition(0, degrees);
      LM.setPosition(0, degrees);
      LB.setPosition(0, degrees);
      RF.setPosition(0, degrees);
      RM.setPosition(0, degrees);
      RB.setPosition(0, degrees);
    }
  
    int leftMotorPosition = LF.position(degrees);
    int rightMotorPosition = RF.position(degrees);


    ////////////
    //Movement//
    ////////////
    
    int avgPosition = (leftMotorPosition + rightMotorPosition) / 2;

    // proportional
    error = desiredValue - avgPosition;

    // derivative
    derivative = error - prevError;

    // integral
    totalError += error;

    double lateralMotorPower = error * kP + derivative * kD + totalError * kI;

    ///////////
    //Turning//
    ///////////

    int turnDifference = leftMotorPosition - rightMotorPosition;

    // proportional
    turnError = desiredTurnValue - turnDifference;

    // derivative
    turnDerivative = turnError - turnPrevError;

    // integral    
    turnTotalError += turnError;

    double turnMotorPower = turnError * tkP + turnDerivative * tkD + turnTotalError * tkI;

    if ((abs(error) < marginOfError && abs(turnError) < marginOfError) || count >= 100) {
      LF.stop(coast);
      LM.stop(coast);
      LB.stop(coast);
      RF.stop(coast);
      RM.stop(coast);
      RB.stop(coast);
      break;
    }

    LF.spin(forward, lateralMotorPower + turnMotorPower, volt);
    RF.spin(forward, lateralMotorPower - turnMotorPower, volt);
    LM.spin(forward, lateralMotorPower + turnMotorPower, volt);
    RM.spin(forward, lateralMotorPower - turnMotorPower, volt);
    LB.spin(forward, lateralMotorPower + turnMotorPower, volt);
    RB.spin(forward, lateralMotorPower - turnMotorPower, volt);
    prevError = error;
    turnPrevError = turnError;

    wait(20, msec);
    count++;
  }

  return 1;
}