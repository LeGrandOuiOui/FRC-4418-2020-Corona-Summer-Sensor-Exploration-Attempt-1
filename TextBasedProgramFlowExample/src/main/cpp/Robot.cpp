/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>

// #include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include "Robot.h"
#include "Drivetrain.h"
#include "StatusDisplay.h"

// TODO: Globally, change all copy-initializations to brace-initializations
// Default values for the robot's Properties
Robotmap::DriveModes Robot::driveMode   = Robotmap::DriveModes::ARCADE_MODE;
double Robot::motorsSpeed               = 0.0;
bool Robot::isLoading                   = false;
bool Robot::isShooting                  = false;
bool Robot::isManiping                  = false;
bool Robot::isTargeting                 = false;


// Default ports and channels for robot Input Devices
frc::XboxController Robot::xboxController{ Robotmap::XBOXCONTROLLER_PORT };



void Robot::RobotInit()
{
  // m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  // m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  // frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  statusDisplay.populate_display();
}

void Robot::RobotPeriodic()
{
  statusDisplay.update_display_values().update_display();
}

void Robot::AutonomousInit()
{
  // m_autoSelected = m_chooser.GetSelected();
  // // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  // //     kAutoNameDefault);
  // std::cout << "Auto selected: " << m_autoSelected << '\n';

  // if (m_autoSelected == kAutoNameCustom) {
  //   // Custom Auto goes here
  // } else {
  //   // Default Auto goes here
  // }
}

void Robot::AutonomousPeriodic()
{
  // if (m_autoSelected == kAutoNameCustom) {
  //   // Custom Auto goes here
  // } else {
  //   // Default Auto goes here
  // }
}

void Robot::TeleopInit()
{

}

void Robot::TeleopPeriodic()
{
  drivetrain.checkAndExecDriveMode();
  std::cout << std::boolalpha << "Test button pressed? " << xboxController.GetBackButtonPressed() << '\n';
}

void Robot::DisabledInit()
{
  
}

void Robot::DisabledPeriodic() {
  
}

void Robot::TestInit() {

}

void Robot::TestPeriodic() {
  
}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
