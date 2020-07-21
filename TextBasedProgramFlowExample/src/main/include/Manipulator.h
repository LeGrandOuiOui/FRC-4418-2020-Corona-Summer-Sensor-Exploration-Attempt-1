/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

class Manipulator {
private:
  enum ELBOW_DIRS {
    UP,
    DOWN
  };
public:
  Manipulator() = default;

  void checkAndExec();

  void moveElbow(const ELBOW_DIRS&);
    // Only declared for design continuity and as an academic text-based example
  // void spinHand();
};
