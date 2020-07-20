/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>

#include "Robot.h"
#include "Robotmap.h"
#include "Drivetrain.h"


void Drivetrain::checkAndExecDriveMode() {
    if (Robot::getDriveMode() == Robotmap::DriveModes::ARCADE_MODE)
        arcadeDrive();
    else if (Robot::getDriveMode() == Robotmap::DriveModes::TANK_MODE)
        tankDrive();
    else
        std::cout << "DRIVETRAIN ERROR: Unknown driveMode evaluated\n";
}

void Drivetrain::arcadeDrive() {
    // Get absolute distance from joystick center for printing motor speed
    Robot::setMotorsSpeed(sqrt(
        pow(Robot::xboxController.GetX(frc::GenericHID::kLeftHand), 2.0) + 
        pow(Robot::xboxController.GetY(frc::GenericHID::kLeftHand), 2.0) 
    ));
}

void Drivetrain::tankDrive() {
    // Get average of y-axis values from both joysticks
    Robot::setMotorsSpeed(
        ( Robot::xboxController.GetY(frc::GenericHID::kLeftHand) + Robot::xboxController.GetY(frc::GenericHID::kRightHand) )
            / 2.0
    );
}