/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Loader.h"
#include "Robot.h"

void Loader::checkAndSpinLoader() {
    if (Robot::xboxController.GetBumper(frc::GenericHID::kRightHand))
        Robot::setIsLoading(true);
}
