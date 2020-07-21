/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Targeting.h"
#include "Robot.h"

void Targeting::checkAndExec() {
    if (Robot::xboxController.GetBButtonPressed())
        if (Robot::getIsTargeting())
            Robot::setIsTargeting(false);
        else
            Robot::setIsTargeting(true);
    if (Robot::getIsTargeting())
        execAlgorithm();
}

void Targeting::execAlgorithm() {
        // lmao vision team = #1
    std::cout << "Executing super-awesome, semi-automous algorithm\n";
}