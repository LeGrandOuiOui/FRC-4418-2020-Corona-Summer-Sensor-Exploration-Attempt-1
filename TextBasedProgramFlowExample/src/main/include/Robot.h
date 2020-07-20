/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
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
  static Robotmap::DriveModes driveMode;    // Modes include "Arcade" and "Tank"
  static double motorsSpeed;                // Max of 1.0, min of 0.0
  static bool isLoading;                    // Triggered would be "Spinning", idle would be "Idle"
  static bool isShooting;                   // Triggered would be "Firing", idle would be "Cold"
  static bool isTargeting;                  // Triggered would be "Activated", idle would be "Deactivated"

  // Properties Getters and Setters
public:
  static const Robotmap::DriveModes& 
    getDriveMode() { return driveMode; }
  static void 
    setDriveMode(const Robotmap::DriveModes& newDriveMode) { driveMode = newDriveMode; }

  static const double
    getMotorsSpeed() { return motorsSpeed; }
  static void 
    setMotorsSpeed(const double newMotorsSpeed) { motorsSpeed = newMotorsSpeed; }
  
  static const bool 
    getIsLoading() { return isLoading; };
  static void
    setIsLoading(const bool newIsLoading) { isLoading = newIsLoading; }
  
  static const bool
    getIsShooting() { return isShooting; }
  static void
    setIsShooting(const bool newIsShooting) { isShooting = newIsShooting; }
  
  static const bool
    getIsTargeting() { return isTargeting; }
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


// Default values for the robot's Properties
Robotmap::DriveModes Robot::driveMode   = Robotmap::DriveModes::ARCADE_MODE;
double Robot::motorsSpeed{ 0.0 };
bool Robot::isLoading                   = false;
bool Robot::isShooting                  = false;
bool Robot::isTargeting                 = false;


// Default ports and channels for robot Input Devices
frc::XboxController Robot::xboxController{ Robotmap::XBOXCONTROLLER_PORT };