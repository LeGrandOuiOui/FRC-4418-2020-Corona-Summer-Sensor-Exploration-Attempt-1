/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Robotmap.h"


class Drivetrain
{
private:
  Robotmap::DriveModes lastTwoJoyOption = Robotmap::DriveModes::TANK_MODE;    // default TANK or DRONE toggle is TANK
public:
  Drivetrain() = default;

  inline const Robotmap::DriveModes& getLastTwoJoyOption() {
    return lastTwoJoyOption;
  }
  inline void setLastTwoJoyOption(const Robotmap::DriveModes& newLastTwoJoyOption) {
    lastTwoJoyOption = newLastTwoJoyOption;
  }

  void checkAndExec();

  void arcadeDrive();
  void tankDrive();
  void droneDrive();    // left joystick Y-axis controls speed, right joystick XY controls direction
};