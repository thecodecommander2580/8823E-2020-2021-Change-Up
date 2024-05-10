using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern light Light;
extern motor29 Flash_Light1;
extern motor29 Flash_Light2;
extern limit Ball_Senser;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );