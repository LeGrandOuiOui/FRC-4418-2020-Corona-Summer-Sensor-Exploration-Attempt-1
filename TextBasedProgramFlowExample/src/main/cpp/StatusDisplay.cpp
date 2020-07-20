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
        .WithSize(40, 30)
        .GetEntry();
    driveModeStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Drive Mode", driveModeToString())
        .WithWidget(frc::BuiltInWidgets::kTextView)
        .WithSize(30,30)
        .GetEntry();
    motorDriveSpeedStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Motors Speed", motorDriveSpeed)
        .WithWidget(frc::BuiltInWidgets::kDial)
        .WithSize(50,50)
        .GetEntry();
    loaderStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Loader", loaderStatusToString())
        .WithWidget(frc::BuiltInWidgets::kTextView)
        .WithSize(30,25)
        .GetEntry();
    shooterStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Shooter", shooterStatusToString())
        .WithWidget(frc::BuiltInWidgets::kTextView)
        .WithSize(30,25)
        .GetEntry();
    targetingStatus = frc::Shuffleboard::GetTab(statusTabName)
        .Add("Targeting", targetingStatusToString())
        .WithWidget(frc::BuiltInWidgets::kTextView)
        .WithSize(30,25)
        .GetEntry();
}

void StatusDisplay::update_statuses() {
    stateStatus.SetString(robotStateToString());
    driveModeStatus.SetString(driveModeToString());
    motorDriveSpeedStatus.SetDouble(motorDriveSpeed);
    loaderStatus.SetString(loaderStatusToString());
    shooterStatus.SetString(shooterStatusToString());
    targetingStatus.SetString(targetingStatusToString());
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

const wpi::Twine StatusDisplay::loaderStatusToString() const {
    if (loading)
        return wpi::Twine("Spinning");
    else
        return wpi::Twine("Idle");
}

const wpi::Twine StatusDisplay::shooterStatusToString() const {
    if (shooting)
        return wpi::Twine("Firing");
    else
        return wpi::Twine("Cold");
}

const wpi::Twine StatusDisplay::targetingStatusToString() {
    if (targeting)
    return wpi::Twine("Activated");
    else
        return wpi::Twine("Deactivated");
}