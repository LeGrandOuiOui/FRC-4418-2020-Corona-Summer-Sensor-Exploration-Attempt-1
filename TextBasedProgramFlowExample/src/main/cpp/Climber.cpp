/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>

#include "Climber.h"
#include "Robot.h"

void Climber::checkAndExec() {
    if (Robot::xboxController.GetYButton() && !Robot::xboxController.GetAButton())
        moveClimber(Climber::UP);
    else if (!Robot::xboxController.GetYButton() && Robot::xboxController.GetAButton())
        moveClimber(Climber::DOWN);
    else
        Robot::setIsClimbing(false);
}

void Climber::moveClimber(const Climber::DIR& direction) {
    switch (direction) {
        case Climber::UP:
        case Climber::DOWN:
            Robot::setIsClimbing(true);
            break;
        default:
            Robot::setIsClimbing(false);
            std::cout << "CLIMBER ERROR: Unknown direction evaluated to climb\n";
            break;
    }
}
