#pragma once
#include "lemlib/api.hpp"
#include "api.h"

//chassis
extern lemlib::Chassis chassis;
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;
extern pros::Imu imu;

//subsystem
//pneumatics
extern pros::ADIDigitalOut frontwings;
extern pros::ADIDigitalOut lift;
extern pros::ADIDigitalOut blwing;
extern pros::ADIDigitalOut brwing;
extern pros::ADIDigitalOut intakepist;

//motors
extern pros::MotorGroup intake;
extern pros::Controller master;
extern pros::Distance dist;