#include "vex.h"
#include "drivetrainpid.h"

using namespace vex;

void start() {
  Flywheel.setVelocity(500, percent);
  Intake.setVelocity(150, percent);
  
  Wings.set(false);
  IntakePistons.set(false);

  // just to make sure the robot actually downloaded the code
  Brain.Screen.print("Edit: 6");
}

/* new pid values */
double kP = 0.03; // proportional
double kI = 0.00005; // integral
double kD = 0.001; // derivative

double tkP = 0.05; // proportional
double tkI = 0.00005; // integral
double tkD = 0.001; // derivative

// the drive is much faster and the turning is more accurate (hopefully for extremely small/large values as well)

/* old pid values */
// double kP = 0.0035; // proportional
// double kI = 0.0001; // integral
// double kD = 0.007; // derivative

// double tkP = 0.03; // proportional
// double tkI = 0.00005; // integral (really close to 0)
// double tkD = 0.05; // derivative

double turnConversion =  48/36;

int error; // positive difference between sensor value and desired value (positional)
int prevError; // position of the robot 20 milliseconds ago
int derivative; // error - prevError (speed)
int totalError; // totalError = totalError + error

int turnError; // positive difference between sensor value and desired value (positional)
int turnPrevError; // position of the robot 20 milliseconds ago
int turnDerivative; // error - prevError (speed)
int turnTotalError; // totalError = totalError + error

int marginOfError = 25;

int drivePID(int desiredValue, int desiredTurnValue) {

  desiredTurnValue *= turnConversion;

  int count = 0;

  bool resetDriveSensors = 1;

  while(true) {

    if (resetDriveSensors) {
      resetDriveSensors = 0;
      LF.setPosition(0, degrees);
      LM.setPosition(0, degrees);
      LB.setPosition(0, degrees);
      RF.setPosition(0, degrees);
      RM.setPosition(0, degrees);
      RB.setPosition(0, degrees);
    }
  
    int leftMotorPosition = LB.position(degrees);
    int rightMotorPosition = RB.position(degrees);


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