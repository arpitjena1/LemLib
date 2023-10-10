#include "config.h"


//chassis---
pros::Motor lF(-9, pros::E_MOTOR_GEARSET_06); // left front motor. port 9, reversed
pros::Motor lM(-9, pros::E_MOTOR_GEARSET_06); // left front motor. port 9, reversed
pros::Motor lB(-21, pros::E_MOTOR_GEARSET_06); // left back motor. port 21, reversed
pros::Motor rF(12, pros::E_MOTOR_GEARSET_06); // right front motor. port 12
pros::Motor rM(9, pros::E_MOTOR_GEARSET_06); // left front motor. port 9, reversed
pros::Motor rB(16, pros::E_MOTOR_GEARSET_06); // right back motor. port 16

// motor groups
pros::MotorGroup leftMotors({lF, lM, lB}); // left motor group
pros::MotorGroup rightMotors({rF, rM, rB}); // right motor group

// Inertial Sensor on port 10
pros::Imu imu(10);

// tracking wheels
pros::Rotation leftEnc(1);
pros::Rotation rightEnc(-7);
// horizontal tracking wheel. 2.75" diameter, 3.7" offset, back of the robot
lemlib::TrackingWheel left(&leftEnc, lemlib::Omniwheel::NEW_325, -3.7);
lemlib::TrackingWheel right(&rightEnc, lemlib::Omniwheel::NEW_325, 3.7);

// drivetrain
lemlib::Drivetrain_t drivetrain {&leftMotors, &rightMotors, 10, lemlib::Omniwheel::NEW_325, 360, 2};

// lateral motion controller
lemlib::ChassisController_t lateralController {10, 30, 1, 100, 3, 500, 20};

// angular motion controller
lemlib::ChassisController_t angularController {2, 10, 1, 100, 3, 500, 20};

// sensors for odometry
lemlib::OdomSensors_t sensors {&left, &right, nullptr, nullptr, &imu};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);


//subsystem
pros::Motor intaketop(12);
pros::Motor intakebottom(13);
pros::MotorGroup intake({intaketop, intakebottom});
pros::Optical optical(13);
pros::Distance dist(21);
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::ADIDigitalOut blwing('D');
pros::ADIDigitalOut brwing('D');
pros::ADIDigitalOut intakepist('F');
pros::ADIDigitalOut frontwings('A');
pros::ADIDigitalOut lift('A');
pros::Vision vision(2);