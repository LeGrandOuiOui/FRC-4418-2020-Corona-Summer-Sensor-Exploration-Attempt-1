/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "StatusDisplay.h"


StatusDisplay& StatusDisplay::populate_display() {
    robotStateNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Status Narration", robotStateToString())
        .WithWidget(frc::BuiltInWidgets::kTextView)
        .WithSize(3,1)
        .WithPosition(3,0)
        .GetEntry();
    
    driveModeNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Drive Mode", driveModeToString())
        .WithWidget(frc::BuiltInWidgets::kTextView)
        .WithSize(2,2)
        .WithPosition(6,1)
        .GetEntry();
        
    motorsSpeedNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Motors Speed", motorDriveSpeed)
        .WithWidget(frc::BuiltInWidgets::kDial)
        .WithSize(2,2)
        .WithPosition(1,1)
        .GetEntry();
    
    loaderBoolNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Loader", isLoadingStatus)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .WithSize(1,3)
        .WithPosition(3,1)
        .GetEntry();
    
    shooterBoolNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Shooter", isShootingStatus)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .WithSize(1,3)
        .WithPosition(4,1)
        .GetEntry();
    
    targetingBoolNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Targeting", isTargetingStatus)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .WithSize(1,3)
        .WithPosition(5,1)
        .GetEntry();
    
    return *this;
}

StatusDisplay& StatusDisplay::update_display() {
    robotStateNE.SetString(robotStateToString());
    driveModeNE.SetString(driveModeToString());
    motorsSpeedNE.SetDouble(motorDriveSpeed);
    loaderBoolNE.SetBoolean(isLoadingStatus);
    shooterBoolNE.SetBoolean(isShootingStatus);
    targetingBoolNE.SetBoolean(isTargetingStatus);
    
    return *this;
}

StatusDisplay& update_display_values() {

}



const wpi::Twine StatusDisplay::robotStateToString() const {
    switch (robotStateStatus) {
        case Robotmap::RobotStates::IDLE_STATE:
            return wpi::Twine("Idle");
            break;
        case Robotmap::RobotStates::DRIVING_STATE:
            return wpi::Twine("Driving");
            break;
        case Robotmap::RobotStates::FIRING_STATE:
            return wpi::Twine("Firing Shooter");
            break;
        case Robotmap::RobotStates::LOADING_STATE:
            return wpi::Twine("Loading Shooter");
            break;
        case Robotmap::RobotStates::TARGETING_STATE:
            return wpi::Twine("Targeting Goal");
            break;
        case Robotmap::RobotStates::MANIPULATING_STATE:
            return wpi::Twine("Moving Manipulator");
            break;
        case Robotmap::RobotStates::CLIMBING_STATE:
            return wpi::Twine("Climbing");
            break;
        case Robotmap::RobotStates::AUTONOMOUS_STATE:
            return wpi::Twine("Autonomous");
            break;
        default:
            return wpi::Twine("UNKNOWN STATE");
            break;
        }
}

const wpi::Twine StatusDisplay::driveModeToString() const {
    switch (driveModeStatus) {
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