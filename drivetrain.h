#pragma once
#include "vector2d.h"
#include <cmath>

class Drivetrain
{
public:
    float engineTorque;
    float brakeTorque;
    float maxEngineTorque;
    float maxBrakeTorque;

    float gearRatio;
    float finalDriveRatio;
    float efficiency;

    Drivetrain()
    {
        engineTorque = 0.0f;
        brakeTorque = 0.0f;
        maxEngineTorque = 800.0f;
        maxBrakeTorque = 1200.0f;

        gearRatio = 3.5f;
        finalDriveRatio = 3.2f;
        efficiency = 0.9f;
    }

    Drivetrain(
        float maxEng,
        float maxBrk,
        float gear,
        float finalDrive,
        float eff
    )
    {
        engineTorque = 0.0f;
        brakeTorque = 0.0f;
        maxEngineTorque = maxEng;
        maxBrakeTorque = maxBrk;

        gearRatio = gear;
        finalDriveRatio = finalDrive;
        efficiency = eff;
    }

    void setThrottle(float throttle)
    {
        if (throttle < 0.0f) throttle = 0.0f;
        if (throttle > 1.0f) throttle = 1.0f;
        engineTorque = throttle * maxEngineTorque;
    }

    void setBrake(float brake)
    {
        if (brake < 0.0f) brake = 0.0f;
        if (brake > 1.0f) brake = 1.0f;
        brakeTorque = brake * maxBrakeTorque;
    }

    float computeWheelTorque() const
    {
        float drive = engineTorque * gearRatio * finalDriveRatio * efficiency;
        float brake = brakeTorque;
        return drive - brake;
    }

    float computeLongitudinalForce(float wheelRadius) const
    {
        if (wheelRadius <= 0.0f) return 0.0f;
        return computeWheelTorque() / wheelRadius;
    }
};
