/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Manipulator.h"
#include "Robot.h"

void Manipulator::checkAndExec() {
    if (Robot::xboxUpPOV.Get() && !Robot::xboxDownPOV.Get())
        moveElbow(Manipulator::UP);
    else if (!Robot::xboxUpPOV.Get() && Robot::xboxDownPOV.Get())
        moveElbow(Manipulator::DOWN);
    else
        Robot::setIsMovingManip(false);
    
    if (Robot::xboxController.GetXButton())
        spinHand();
    else
        Robot::setIsSpinningManip(false);
}

void Manipulator::moveElbow(const Manipulator::ELBOW_DIRS& elbowDir) {
    switch (elbowDir) {
        case Manipulator::UP:
        case Manipulator::DOWN:
            Robot::setIsMovingManip(true);
            break;
        default:
            Robot::setIsMovingManip(false);
            std::cout << "MANIPULATOR ERROR: Unknown elbow direction evaluated\n";
            break;
    }
}

void Manipulator::spinHand() {
    Robot::setIsSpinningManip(true);
}