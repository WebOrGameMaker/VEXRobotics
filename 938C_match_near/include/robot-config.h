using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LF;
extern motor LM;
extern motor LB;
extern motor RF;
extern motor RM;
extern motor RB;
extern motor Flywheel;
extern controller Controller1;
extern digital_out Wings;
extern digital_out IntakePistons;
extern motor Intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );