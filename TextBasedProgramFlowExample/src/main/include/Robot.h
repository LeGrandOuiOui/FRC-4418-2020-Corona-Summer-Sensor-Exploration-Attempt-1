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

class Robot : public frc::TimedRobot {
  private:
    // frc::SendableChooser<std::string> m_chooser;
    // const std::string kAutoNameDefault = "Default";
    // const std::string kAutoNameCustom = "My Auto";
    // std::string m_autoSelected;

    const std::string statusTabName = "Test Tab Aight?"; 

    // int testCounter = 0;

    // nt::NetworkTableEntry networkCounter;
    // wpi::StringMap<std::shared_ptr<nt::Value>> networkCounterProperties = {
    //   std::make_pair("min", nt::Value::MakeDouble(0)),
    //   std::make_pair("max", nt::Value::MakeDouble(1000))
    // };

    std::string robotStatus = "Idle";     // Other states include "Driving", "Firing", "Loading", 
                                                               // "Targeting", "Manipulating", "Climbing", "Autonomous"
    double motorDriveSpeed = 0.0;         // Max of 1.0
    std::string loaderStatus = "Idle";    // opposite would be "Spinning"
    std::string shooterStatus = "Idle";   // opposite would be "Firing"
    std::string targetingStatus = "Deactivated";

  public:
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

    const std::string& getRobotStatus() const {
      return robotStatus;
    }

    void setRobotStatus(const std::string& newStatus) {
      robotStatus = newStatus;
    }
};
