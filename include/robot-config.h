using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftFrontBase;
extern motor LeftBackBase;
extern motor RightFrontBase;
extern motor RightBackBase;
extern motor LeftIntake;
extern motor RightIntake;
extern motor Chamber;
extern motor Shooter;
extern controller Controller1;
extern inertial Inertial;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );