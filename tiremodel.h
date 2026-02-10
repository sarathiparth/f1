#pragma once
#include "vector2d.h"
#include <cmath>

class TireModel
{
public:
    float grip;
    float rollingResistance;
    float maxSlip;
    float corneringStiffness;

    TireModel()
    {
        grip = 1.0f;
        rollingResistance = 0.015f;
        maxSlip = 1.0f;
        corneringStiffness = 5.0f;
    }

    TireModel(
        float g,
        float rr,
        float ms,
        float cs
    )
    {
        grip = g;
        rollingResistance = rr;
        maxSlip = ms;
        corneringStiffness = cs;
    }

    Vector2 lateralForce(
        const Vector2& lateralVelocity,
        float normalForce
    ) const
    {
        float slip = lateralVelocity.magnitude();
        float clamped = slip > maxSlip ? maxSlip : slip;

        if (slip == 0.0f)
            return Vector2();

        Vector2 dir = lateralVelocity.normalized() * -1.0f;
        return dir * (corneringStiffness * clamped * normalForce * grip);
    }

    Vector2 longitudinalForce(
        float slipRatio,
        float normalForce
    ) const
    {
        float clamped =
            slipRatio > maxSlip ? maxSlip :
            (slipRatio < -maxSlip ? -maxSlip : slipRatio);

        return Vector2(clamped * normalForce * grip, 0.0f);
    }

    float rollingDrag(float normalForce) const
    {
        return normalForce * rollingResistance;
    }
};
