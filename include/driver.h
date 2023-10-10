#include "api.h"
#include "config.h"

#define INTAKE_DIST  100
#define BALL_SIG 2 // Defines the vision signature that is trained for the ball
#define BASE_P 0.6 // The Kp for X error / base power
#define BASE_DISTANCE_WIDTH 40


extern void autonomousintaketask();
extern void driver();
pros::vision_object_s_t calculateVision();
void monitorVisionTask(void*);