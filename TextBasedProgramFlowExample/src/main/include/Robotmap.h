/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

class Robotmap {
 public:
  Robotmap() = default;

  enum class RobotStates {
      IDLE_STATE,
      DRIVING_STATE,
      FIRING_STATE,
      LOADING_STATE,
      TARGETING_STATE,
      MANIPULATING_STATE,
      CLIMBING_STATE,
      AUTONOMOUS_STATE
  };

  enum class DriveModes {
      ARCADE_MODE,
      TANK_MODE
  };
};
