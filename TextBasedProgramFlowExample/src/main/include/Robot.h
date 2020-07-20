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

#include "Robotmap.h"

#include "StatusDisplay.h"
#include "Drivetrain.h"


class Robot : public frc::TimedRobot
{
private:
  // frc::SendableChooser<std::string> m_chooser;
  // const std::string kAutoNameDefault = "Default";
  // const std::string kAutoNameCustom = "My Auto";
  // std::string m_autoSelected;

  // int testCounter = 0;

  // nt::NetworkTableEntry networkCounter;
  // wpi::StringMap<std::shared_ptr<nt::Value>> networkCounterProperties = {
  //   std::make_pair("min", nt::Value::MakeDouble(0)),
  //   std::make_pair("max", nt::Value::MakeDouble(1000))
  // };


  // Properties
  static Robotmap::DriveModes   driveMode;
  static double                 motorsSpeed;            
  static bool                   isLoading;                
  static bool                   isShooting;               
  static bool                   isManiping;   // shorthand for isManipulating
  static bool                   isTargeting;              

  // Properties Getters and Setters
public:
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
    getIsManiping() { return isManiping; }
  inline static void
    setIsManiping(const bool newIsManiping) { isManiping = newIsManiping; }

  inline static const bool&
    getIsTargeting() { return isTargeting; }
  inline static void
    setIsTargeting(const bool newIsTargeting) { isTargeting = newIsTargeting; }

private:
  // Subways
  StatusDisplay statusDisplay;
  Drivetrain drivetrain;

public:
  // Input Devices
  static frc::XboxController xboxController;

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