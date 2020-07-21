/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>

// #include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/DigitalInput.h>
#include <frc/AnalogPotentiometer.h>
#include <frc/Ultrasonic.h>

#include "Robot.h"
#include "Drivetrain.h"
#include "StatusDisplay.h"

// Default values for the robot's Properties
Robotmap::DriveModes Robot::driveMode   { Robotmap::DriveModes::ARCADE_MODE };
double Robot::motorsSpeed               { 0.0 };
bool Robot::isLoading                   { false };
bool Robot::isShooting                  { false };
bool Robot::isClimbing                  { false };
bool Robot::isMovingManip               { false };
bool Robot::isSpinningManip             { false };
bool Robot::isTargeting                 { false };


    // Example of setting up a ping-response ultrasonic sensor
// frc::Ultrasonic ultrasonicSensor{ 7, 8, frc::Ultrasonic::kMilliMeters };


// Default ports and channels for robot Input Devices
frc::XboxController Robot::xboxController{ Robotmap::XBOXCONTROLLER_PORT };
  // note: pov index represents WHICH POV-pad on the controller. Example: If a controller had two POV-pads,
    // the second POV-pad would be at index 1 (0-based index)
frc::POVButton Robot::xboxUpPOV{ Robot::xboxController, Robotmap::XBOX_UP_POV_ANGLE };
frc::POVButton Robot::xboxDownPOV{ Robot::xboxController, Robotmap::XBOX_DOWN_POV_ANGLE };



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
  drivetrain.checkAndExec();
  loader.checkAndExec();
  shooter.checkAndExec();
  manipulator.checkAndExec();
  climber.checkAndExec();
  targeting.checkAndExec();
}

void Robot::DisabledInit()
{
  
}

void Robot::DisabledPeriodic() {
  
}

void Robot::TestInit() {
      // Make sure to turn on the WPILIB automatic mode for valid ping-ultrasonic output
  // ultrasonicSensor.SetAutomaticMode(true);
}

void Robot::TestPeriodic() {
  // Example of how to use PIR sensors
  // frc::DigitalInput pirSensor{ 8 };
  // std::cout << "PIR Digital Output: " << pirSensor.Get() << '\n';

      // Example of how to use analog infrared (distance-measuring) sensors
  // frc::AnalogPotentiometer analogIRSensor{ 2 };
  // std::cout << "IR Analog Output: " << analogIRSensor.Get() << '\n';

      // Example of how to use ping-response (trigger) ultrasonic sensors
  // std::cout << "Ping-Ultrasonic Output: ";
  // if (ultrasonicSensor.IsRangeValid())
  //   std::cout << ultrasonicSensor.GetRangeMM() << '\n';
  // else
  //   std::cout << " NO VALID MEASUREMENTS\n";
}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
