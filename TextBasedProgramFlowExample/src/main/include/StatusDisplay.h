/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <networktables/NetworkTableEntry.h>
#include <wpi/Twine.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include "Robotmap.h"

class StatusDisplay {
  private:

    friend class Robot;


    const std::string statusTabName = "Test Tab Aight?";
    
    Robotmap::RobotStates robotStateStatus = Robotmap::RobotStates::IDLE_STATE;     // Other states include "Driving", "Firing", "Loading", 
                                                               // "Targeting", "Manipulating", "Climbing", "Autonomous"
    Robotmap::DriveModes driveModeStatus = Robotmap::DriveModes::ARCADE_MODE;      // Modes include "Arcade" and "Tank"
    double motorsSpeed = 0.0;            // Max of 1.0, min of 0.0
    bool loading = false;                    // Triggered would be "Spinning", idle would be "Idle"
    bool shooting = false;                   // Triggered would be "Firing", idle would be "Cold"
    bool targeting = false;                  // Triggered would be "Activated", idle would be "Deactivated"

    nt::NetworkTableEntry robotStateNE;
    nt::NetworkTableEntry driveModeNE;
    nt::NetworkTableEntry motorsSpeedNE;
    nt::NetworkTableEntry loaderBoolNE;
    nt::NetworkTableEntry shooterBoolNE;
    nt::NetworkTableEntry targetingBoolNE;


    const wpi::Twine robotStateToString() const;
    const wpi::Twine driveModeToString() const;

  public:
    StatusDisplay() = default;

    void populate_display();

    void update_statuses();
};
