/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
// #include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/XboxController.h>
#include <frc/buttons/POVButton.h>

#include "Robotmap.h"

#include "StatusDisplay.h"
#include "Drivetrain.h"
#include "Loader.h"
#include "Shooter.h"
#include "Manipulator.h"
#include "Climber.h"
#include "Targeting.h"


class Robot : public frc::TimedRobot
{
private:
  // frc::SendableChooser<std::string> m_chooser;
  // const std::string kAutoNameDefault = "Default";
  // const std::string kAutoNameCustom = "My Auto";
  // std::string m_autoSelected;

  // Properties
  static Robotmap::DriveModes   driveMode;
  static double                 motorsSpeed;            
  static bool                   isLoading;                
  static bool                   isShooting;
  static bool                   isClimbing;               
  static bool                   isMovingManip;    // shorthand for isMovingManipulator
  static bool                   isSpinningManip;  // shorthand for isSpinningManipulator
  static bool                   isTargeting;              

  // Properties Getters and Setters
public:
  // inlined for efficiency and returns references to primitive types due to need for const-getting
  inline static Robotmap::DriveModes& 
    getDriveMode() { return driveMode; }
  inline static void 
    setDriveMode(const Robotmap::DriveModes& newDriveMode) { driveMode = newDriveMode; }

  inline static const double&
    getMotorsSpeed() { return motorsSpeed; }
  inline static void 
    setMotorsSpeed(const double newMotorsSpeed) { motorsSpeed = newMotorsSpeed; }
  
  inline static const bool& 
    getIsLoading() { return isLoading; };
  inline static void
    setIsLoading(const bool newIsLoading) { isLoading = newIsLoading; }
  
  inline static const bool&
    getIsShooting() { return isShooting; }
  inline static void
    setIsShooting(const bool newIsShooting) { isShooting = newIsShooting; }
  
  inline static const bool&
    getIsClimbing() { return isClimbing; }
  inline static void
    setIsClimbing(const bool newIsClimbing) { isClimbing = newIsClimbing; }
    
  inline static const bool&
    getIsMovingManip() { return isMovingManip; }
  inline static void
    setIsMovingManip(const bool newIsMovingManip) { isMovingManip = newIsMovingManip; }

  inline static const bool&
    getIsSpinningManip() { return isSpinningManip; }
  inline static void
    setIsSpinningManip(const bool newIsSpinningManip) { isSpinningManip = newIsSpinningManip; }

  inline static const bool&
    getIsTargeting() { return isTargeting; }
  inline static void
    setIsTargeting(const bool newIsTargeting) { isTargeting = newIsTargeting; }

private:
  // Subways
  StatusDisplay statusDisplay;
  Drivetrain drivetrain;
  Loader loader;
  Shooter shooter;
  Manipulator manipulator;
  Climber climber;
  Targeting targeting;

public:
  // Input Devices
  static frc::XboxController xboxController;
  static frc::POVButton xboxUpPOV;
  static frc::POVButton xboxDownPOV;


  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
};