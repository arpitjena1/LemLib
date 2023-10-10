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

float driverangle(){
    int x_error = calculateVision().x_middle_coord - VISION_FOV_WIDTH/2;
            float finalBasePower;
            if(calculateVision().signature == 255)
            {
                finalBasePower = 0;
            }
            else
            {
                finalBasePower = x_error * BASE_P; // For now a simple P based on X deriviation from the center of the vision
            }
            return finalBasePower; //Returns power to be sent to the base
}

pros::vision_object_s_t visionScannerData;
bool updateVision;

pros::vision_object_s_t calculateVision() //Function to read vision sensor data
{
  updateVision = true;
  return visionScannerData;
}
void monitorVisionTask()
{
  
    if(updateVision)
    {
      visionScannerData = vision.get_by_sig(0, BALL_SIG); // Returns info for largest object of the signature
      updateVision = false;
    }
    pros::delay(10);
  
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
        float baseTurnBias;
	    float baseForwardBias;
        bool inRange;
        while(1){
            //tank control
            chassis.tank(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y )+ ((baseTurnBias/100)*127), master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)-((baseTurnBias/100)*127));

            //vision task
            monitorVisionTask();
            if(dist.get()>10000){
                inRange = true;
            }else{
                inRange = false;
            }

            //vision driver code
            if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && detected == false){
                //check if distance is in range of a triball, if it is use vis
                if(inRange){
                    baseTurnBias = 0;
		    baseForwardBias = 0;
                } else{
                    baseTurnBias = driverangle();
                }
			    
		    } else{
			    baseTurnBias = 0;
			    baseForwardBias = 0;
		    }
        }
        
    });
    
    while(1){
        
    }
}
