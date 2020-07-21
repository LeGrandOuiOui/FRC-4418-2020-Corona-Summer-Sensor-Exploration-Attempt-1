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
        Robot::setIsSpinningManip(true);
    else
        Robot::setIsSpinningManip(false);
}

void Manipulator::moveElbow(const Manipulator::ELBOW_DIRS& elbowDir) {
    if (elbowDir == Manipulator::ELBOW_DIRS::UP || elbowDir == Manipulator::ELBOW_DIRS::DOWN)
        Robot::setIsMovingManip(true);
}

        // Only defined for design continuity and as an academic text-based example
// void Manipulator::spinHand() {
//     Robot::setIsSpinningManip(true);
// }