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

void Drivetrain::checkAndExecDriveMode()
{
    // DM stands for DriveMode
    using DM = Robotmap::DriveModes;
    Robotmap::DriveModes oldDM = Robot::getDriveMode();     // Evaluate just once to prevent constant namespace jumping

    if (Robot::xboxController.GetBackButtonPressed() && !Robot::xboxController.GetStartButtonPressed())
        Robot::setDriveMode(DM::ARCADE_MODE);
    else if (!Robot::xboxController.GetBackButtonPressed() && Robot::xboxController.GetStartButtonPressed()) {
        if (oldDM == DM::TANK_MODE 
        || oldDM == DM::DRONE_MODE) {
            if (oldDM == DM::TANK_MODE)
                Robot::setDriveMode(DM::DRONE_MODE);
            else if (oldDM == DM::DRONE_MODE)
                Robot::setDriveMode(DM::TANK_MODE);
        } else
            Robot::setDriveMode(getLastTwoJoyOption());
        setLastTwoJoyOption(Robot::getDriveMode());
    }


    switch (Robot::getDriveMode())
    {
    case Robotmap::DriveModes::ARCADE_MODE:
        arcadeDrive();
        break;
    case Robotmap::DriveModes::TANK_MODE:
        tankDrive();
        break;
    case Robotmap::DriveModes::DRONE_MODE:
        droneDrive();
        break;
    default:
        std::cout << "DRIVETRAIN ERROR: Unknown driveMode evaluated\n";
        break;
    }
}

void Drivetrain::arcadeDrive()
{
    // Get absolute distance from joystick center for printing motor speed
    Robot::setMotorsSpeed(
        ((pow(Robot::xboxController.GetX(frc::GenericHID::kLeftHand), 2.0)
        + pow(Robot::xboxController.GetY(frc::GenericHID::kLeftHand), 2.0)))
    );
}

void Drivetrain::tankDrive()
{
    // Get absolute average of y-axis values from both joysticks
    Robot::setMotorsSpeed(
        (abs(static_cast<double>(Robot::xboxController.GetY(frc::GenericHID::kLeftHand)+0.0))
        + abs(static_cast<double>(Robot::xboxController.GetY(frc::GenericHID::kRightHand)+0.0)))
        
        / 2.0);
}

void Drivetrain::droneDrive()
{
    // Get absolute value of left joystick y-axis
    Robot::setMotorsSpeed(
        abs(static_cast<double>(Robot::xboxController.GetY(frc::GenericHID::kLeftHand)))
    );
}
