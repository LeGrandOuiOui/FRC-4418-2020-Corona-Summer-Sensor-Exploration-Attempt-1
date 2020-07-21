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
        .WithSize(4,1)
        .WithPosition(3,0)
        .GetEntry();
    
    driveModeNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Drive Mode", driveModeToString())
        .WithWidget(frc::BuiltInWidgets::kTextView)
        .WithSize(2,1)
        .WithPosition(1,3)
        .GetEntry();
        
    motorsSpeedNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Motors Speed", motorsSpeedStatus)
        .WithWidget(frc::BuiltInWidgets::kDial)
        .WithProperties(motorsSpeedNEProperties)
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

    climberBoolNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Climber", isClimbingStatus)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .WithSize(1,3)
        .WithPosition(7,1)
        .GetEntry();

    movingManipBoolNE =
        manipLayoutSB.Add("Elbow", isMovingManipStatus)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .GetEntry();
    spinningManipBoolNE = 
        manipLayoutSB.Add("Hand", isSpinningManipStatus)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .GetEntry();

    targetingBoolNE = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Targeting", isTargetingStatus)
        .WithWidget(frc::BuiltInWidgets::kBooleanBox)
        .WithSize(1,3)
        .WithPosition(5,1)
        .GetEntry();
    
    return *this;
}

StatusDisplay& StatusDisplay::update_display_values() {
    determineRobotStatus();
    driveModeStatus            = Robot::getDriveMode();
    motorsSpeedStatus          = Robot::getMotorsSpeed();
    isLoadingStatus            = Robot::getIsLoading();
    isShootingStatus           = Robot::getIsShooting();
    isClimbingStatus           = Robot::getIsClimbing();
    isMovingManipStatus        = Robot::getIsMovingManip();
    isSpinningManipStatus      = Robot::getIsSpinningManip();
    isTargetingStatus          = Robot::getIsTargeting();

    return *this;
}

StatusDisplay& StatusDisplay::update_display() {
    robotStateNE.SetString(robotStateToString());
    driveModeNE.SetString(driveModeToString());
    motorsSpeedNE.SetDouble(motorsSpeedStatus);
    loaderBoolNE.SetBoolean(isLoadingStatus);
    shooterBoolNE.SetBoolean(isShootingStatus);
    climberBoolNE.SetBoolean(isClimbingStatus);
    movingManipBoolNE.SetBoolean(isMovingManipStatus);
    spinningManipBoolNE.SetBoolean(isSpinningManipStatus);
    targetingBoolNE.SetBoolean(isTargetingStatus);
    
    return *this;
}

void StatusDisplay::determineRobotStatus() {
    // Yes, this function is quite repetitive, but it helps maintain the disconnected control 
        // between the display and the robot's actual state, in the very likely case that 
        // the display needs to become interactive
    using States = Robotmap::RobotStates;
    if (isTargetingStatus) {
        robotStateStatus = States::TARGETING_STATE;
        return;
    }
    if (isClimbingStatus) {
        robotStateStatus = States::CLIMBING_STATE;
        return;
    }
    if (isMovingManipStatus || isSpinningManipStatus) {
        robotStateStatus = States::MANIPULATING_STATE;
        return;
    }
    if (isShootingStatus) {
        robotStateStatus = States::SHOOTING_STATE;
        return;
    }
    if (isLoadingStatus) {
        robotStateStatus = States::LOADING_STATE;
        return;
    }
    if (motorsSpeedStatus > Robotmap::IS_DRIVING_THRESH) {
        robotStateStatus = States::DRIVING_STATE;
        return;
    }

    robotStateStatus = States::IDLE_STATE;
}



const wpi::Twine StatusDisplay::robotStateToString() const {
    using States = Robotmap::RobotStates;
    switch (robotStateStatus) {
        case States::IDLE_STATE:
            return wpi::Twine("Idle");
            break;
        case States::DRIVING_STATE:
            return wpi::Twine("Driving");
            break;
        case States::SHOOTING_STATE:
            return wpi::Twine("Firing Shooter");
            break;
        case States::LOADING_STATE:
            return wpi::Twine("Loading Shooter");
            break;
        case States::TARGETING_STATE:
            return wpi::Twine("Targeting Goal");
            break;
        case States::MANIPULATING_STATE:
            return wpi::Twine("Moving Manipulator");
            break;
        case States::CLIMBING_STATE:
            return wpi::Twine("Climbing");
            break;
        case States::AUTONOMOUS_STATE:
            return wpi::Twine("Autonomous");
            break;
        default:
            return wpi::Twine("UNKNOWN STATE");
            break;
        }
}

const wpi::Twine StatusDisplay::driveModeToString() const {
    switch (driveModeStatus) {
        case Robotmap::DriveModes::ARCADE_MODE:
            return wpi::Twine("Arcade Drive");
            break;
        case Robotmap::DriveModes::TANK_MODE:
            return wpi::Twine("Tank Drive");
            break;
        case Robotmap::DriveModes::DRONE_MODE:
            return wpi::Twine("Drone Drive");
            break;
        default:
            return wpi::Twine("UNKNOWN DRIVE");
            break;
    }
}