/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Shooter.h"
#include "Robot.h"

void Shooter::checkAndExec() {
    if (Robot::xboxController.GetTriggerAxis(frc::GenericHID::kRightHand) 
    > Robotmap::R_TRIGGER_THRESH) {
        Robot::setIsShooting(true);
        return;
    }
    Robot::setIsShooting(false);        // otherwise, shooter should not be spinning
}
