/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "StatusDisplay.h"

void StatusDisplay::populate_display() {
    stateStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Status Narration", robotStateToString())
        .WithWidget(frc::BuiltInWidgets::kTextView)
        .WithSize(3,1)
        .WithPosition(3,0)
        .GetEntry();
    
    driveModeStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Drive Mode", driveModeToString())
        .WithWidget(frc::BuiltInWidgets::kTextView)
        .WithSize(2,2)
        .WithPosition(6,1)
        .GetEntry();
        
    motorSpeedStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Motors Speed", motorDriveSpeed)
        .WithWidget(frc::BuiltInWidgets::kDial)
        .WithSize(2,2)
        .WithPosition(1,1)
        .GetEntry();
    
    loaderStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Loader", loading)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .WithSize(1,3)
        .WithPosition(3,1)
        .GetEntry();
    
    shooterStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Shooter", shooting)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .WithSize(1,3)
        .WithPosition(4,1)
        .GetEntry();
    
    targetingStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Targeting", targeting)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .WithSize(1,3)
        .WithPosition(5,1)
        .GetEntry();
}

void StatusDisplay::update_statuses() {
    stateStatus.SetString(robotStateToString());
    driveModeStatus.SetString(driveModeToString());
    motorSpeedStatus.SetDouble(motorDriveSpeed);
    loaderStatus.SetBoolean(loading);
    shooterStatus.SetBoolean(shooting);
    targetingStatus.SetBoolean(targeting);
}



const wpi::Twine StatusDisplay::robotStateToString() const {
    switch (robotState) {
        case IDLE_STATE:
            return wpi::Twine("Idle");
            break;
        case DRIVING_STATE:
            return wpi::Twine("Driving");
            break;
        case FIRING_STATE:
            return wpi::Twine("Firing Shooter");
            break;
        case LOADING_STATE:
            return wpi::Twine("Loading Shooter");
            break;
        case TARGETING_STATE:
            return wpi::Twine("Targeting Goal");
            break;
        case MANIPULATING_STATE:
            return wpi::Twine("Moving Manipulator");
            break;
        case CLIMBING_STATE:
            return wpi::Twine("Climbing");
            break;
        case AUTONOMOUS_STATE:
            return wpi::Twine("Autonomous");
            break;
        default:
            return wpi::Twine("UNKNOWN STATE");
            break;
        }
}

const wpi::Twine StatusDisplay::driveModeToString() const {
    switch (driveMode) {
        case ARCADE_MODE:
            return wpi::Twine("Arcade Drive");
            break;
        case TANK_MODE:
            return wpi::Twine("Tank Drive");
            break;
        default:
            return wpi::Twine("UNKNOWN DRIVE");
            break;
    }
}