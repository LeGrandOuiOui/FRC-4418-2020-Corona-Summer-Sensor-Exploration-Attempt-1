/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "networktables/NetworkTableEntry.h"
#include "wpi/Twine.h"
#include <frc/shuffleboard/Shuffleboard.h>


class StatusDisplay {
  private:
    enum RobotStates {
      IDLE_STATE,
      DRIVING_STATE,
      FIRING_STATE,
      LOADING_STATE,
      TARGETING_STATE,
      MANIPULATING_STATE,
      CLIMBING_STATE,
      AUTONOMOUS_STATE
    };

    enum DriveModes {
      ARCADE_MODE,
      TANK_MODE
    };


    const std::string statusTabName = "Test Tab Aight?";
    
    RobotStates robotState = IDLE_STATE;     // Other states include "Driving", "Firing", "Loading", 
                                                               // "Targeting", "Manipulating", "Climbing", "Autonomous"
    DriveModes driveMode = ARCADE_MODE;      // Modes include "Arcade" and "Tank"
    double motorDriveSpeed = 0.0;            // Max of 1.0, min of 0.0
    bool loading = false;                    // Triggered would be "Spinning", idle would be "Idle"
    bool shooting = false;                   // Triggered would be "Firing", idle would be "Cold"
    bool targeting = false;                  // Triggered would be "Activated", idle would be "Deactivated"

    nt::NetworkTableEntry stateStatus;
    nt::NetworkTableEntry driveModeStatus;
    nt::NetworkTableEntry motorDriveSpeedStatus;
    nt::NetworkTableEntry loaderStatus;
    nt::NetworkTableEntry shooterStatus;
    nt::NetworkTableEntry targetingStatus;


    const wpi::Twine robotStateToString() const;
    const wpi::Twine driveModeToString() const;
    const wpi::Twine loaderStatusToString() const;
    const wpi::Twine shooterStatusToString() const;
    const wpi::Twine targetingStatusToString();

  public:
    StatusDisplay() = default;

    void populate_display();

    void update_statuses();
};
