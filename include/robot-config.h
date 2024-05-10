using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern limit Ball_Senser;
extern light Light;
extern motor29 Flash_Light1;
extern motor29 Flash_Light2;
extern motor Right_Intake;
extern motor Left_Intake;
extern motor Chamber;
extern motor Upper_Chamber;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );