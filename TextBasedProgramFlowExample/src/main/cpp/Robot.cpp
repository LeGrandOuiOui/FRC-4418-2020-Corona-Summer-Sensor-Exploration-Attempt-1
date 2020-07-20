/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "StatusDisplay.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>

void Robot::RobotInit() {
  // m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  // m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  // frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  // Example of using SmartDashboard for simple number-printing
  // frc::SmartDashboard::PutNumber("SmartDash Test Counter", testCounter);


  // Example of using NetworkTableEntry class for complex widget displaying
    // Adds a number slider that can be seen slowly increasing
  // networkCounter = 
  //   frc::Shuffleboard::GetTab(statusTabName).Add("Network Number", testCounter)
  //                                           .WithWidget(frc::BuiltInWidgets::kNumberSlider)
  //                                           // See Robot.h for super disgusting definition of networkCounterProperties
  //                                           .WithProperties(networkCounterProperties).GetEntry();


  statusDisplay.populate_display();
    
}


void Robot::RobotPeriodic() {
  statusDisplay.update_statuses();
}

void Robot::AutonomousInit() {
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

void Robot::AutonomousPeriodic() {
  // if (m_autoSelected == kAutoNameCustom) {
  //   // Custom Auto goes here
  // } else {
  //   // Default Auto goes here
  // }




}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
  // testCounter++;
  // PutNumber is like a value-updating function, so it must be called periodically
  // frc::SmartDashboard::PutNumber("SmartDash Test Counter", testCounter);

  // Set functions for NetworkTableEntry class must also be called periodically to display updating values
  // networkCounter.SetDouble(testCounter);




}

void Robot::DisabledInit() {
  // testCounter = 0;
  // frc::SmartDashboard::ClearPersistent("SmartDash Test Counter");   // needed to get rid of the pesky default persistence




}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
