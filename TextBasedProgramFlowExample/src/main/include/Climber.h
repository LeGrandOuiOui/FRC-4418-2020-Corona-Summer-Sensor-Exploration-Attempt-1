/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

class Climber {
private:
  enum DIR {
    UP,
    DOWN
  };
public:
  Climber() = default;

  void checkAndExec();
  void moveClimber(const DIR&);
};
