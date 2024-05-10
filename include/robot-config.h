using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LeftBackBase;
extern motor RightBackBase;
extern motor LeftFrontBase;
extern motor RightFrontBase;
extern inertial Inertial;
extern motor Shooter;
extern motor Chamber;
extern motor RightIntake;
extern motor LeftIntake;
extern optical Optical;
extern limit BallDetection;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );