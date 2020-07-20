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
  static Robotmap::DriveModes& 
    getDriveMode() { return const_cast<Robotmap::DriveModes&>(driveMode); }
  static void 
    setDriveMode(const Robotmap::DriveModes& newDriveMode) { driveMode = newDriveMode; }

  static double
    getMotorsSpeed() { return const_cast<double&>(motorsSpeed); }
  static void 
    setMotorsSpeed(const double newMotorsSpeed) { motorsSpeed = newMotorsSpeed; }
  
  static bool 
    getIsLoading() { return const_cast<bool&>(isLoading); };
  static void
    setIsLoading(const bool newIsLoading) { isLoading = newIsLoading; }
  
  static bool
    getIsShooting() { return const_cast<bool&>(isShooting); }
  static void
    setIsShooting(const bool newIsShooting) { isShooting = newIsShooting; }
  
  static bool
    getIsManiping() { return const_cast<bool&>(isManiping); }
  static void
    setIsManiping(const bool newIsManiping) { isManiping = newIsManiping; }

  static bool
    getIsTargeting() { return const_cast<bool&>(isTargeting); }
  static void
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