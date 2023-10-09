#include "driver.h"
#include "pros/misc.h"

bool detected = false;

void autonomousintaketask(){
    
    while(true){
            pros::lcd::print(1,"imu roll- %.2f", imu.get_roll());
            pros::lcd::print(2,"imu pitch- %.2f", imu.get_pitch());
            pros::lcd::print(3,"imu yaw- %.2f", imu.get_yaw());
            pros::lcd::print(4, "imu heading %.2f", imu.get_heading());
			if(dist.get() >= 0 && dist.get() <= INTAKE_DIST){
            detected = true;
        } else{
            detected = false;
        }
    }
}
void driver(){
    bool r1pressed;
    bool r2pressed;
    bool l1pressed;
    bool l2pressed;
    bool apressed;
    bool xpressed;
    bool ypressed;
    bool bpressed;
    bool arrowup;
    bool arrowdown;
    bool arrowleft;
    bool arrowright;
    bool wantToHold;
    int intakeval = 0;
	bool action;
    //driver task
    pros::Task([=](){
        while(1){

            //tank control
            chassis.tank(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
        }
        
    });
    //add rest of driver code
}