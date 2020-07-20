/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "networktables/NetworkTableEntry.h"
#include "wpi/Twine.h"


class StatusDisplay {
  private:
    const std::string statusTabName = "4418 R-Stat Display";
    
      // TODO: Finish hierarchal robot narration for each subway
    Robotmap::RobotStates robotStateStatus 
      = Robotmap::RobotStates::IDLE_STATE;         // Other states include "Driving", "Firing", "Loading", 
                                                        // "Targeting", "Manipulating", "Climbing", "Autonomous"
    Robotmap::DriveModes driveModeStatus 
      = Robotmap::DriveModes::ARCADE_MODE;         // Modes include "Arcade" and "Tank"
    double motorsSpeedStatus = 0.0;                // Max of sqrt(2), min of 0.0
    bool isLoadingStatus = false;
    bool isShootingStatus = false;
    bool isManipingStatus = false;
    bool isTargetingStatus = false;

    nt::NetworkTableEntry robotStateNE;
    nt::NetworkTableEntry driveModeNE;
    nt::NetworkTableEntry motorsSpeedNE;
      wpi::StringMap<std::shared_ptr<nt::Value>> motorsSpeedNEProperties = {
        std::make_pair("min", nt::Value::MakeDouble(0.0)),
        std::make_pair("max", nt::Value::MakeDouble(1.0))
      };
    nt::NetworkTableEntry loaderBoolNE;
    nt::NetworkTableEntry shooterBoolNE;
    nt::NetworkTableEntry manipBoolNE;
    nt::NetworkTableEntry targetingBoolNE;


    const wpi::Twine robotStateToString() const;
    const wpi::Twine driveModeToString() const;

  public:
    StatusDisplay() = default;

    StatusDisplay& populate_display();

    StatusDisplay& update_display();

    StatusDisplay& update_display_values();
};
