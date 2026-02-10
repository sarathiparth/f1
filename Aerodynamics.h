#pragma once
#include "vector2d.h"
#include <cmath>

class Aerodynamics
{
public:
    float airDensity;
    float dragCoefficient;
    float frontalArea;
    float downforceCoefficient;

    Aerodynamics()
    {
        airDensity = 1.225f;
        dragCoefficient = 0.9f;
        frontalArea = 1.5f;
        downforceCoefficient = 3.0f;
    }

    Aerodynamics(
        float rho,
        float cd,
        float area,
        float cl
    )
    {
        airDensity = rho;
        dragCoefficient = cd;
        frontalArea = area;
        downforceCoefficient = cl;
    }

    Vector2 dragForce(const Vector2& velocity) const
    {
        float speed = velocity.magnitude();
        if (speed == 0.0f)
            return Vector2();

        float dragMag =
            0.5f * airDensity * dragCoefficient * frontalArea * speed * speed;

        return velocity.normalized() * -dragMag;
    }

    float downforce(float speed) const
    {
        return 0.5f * airDensity * downforceCoefficient * frontalArea * speed * speed;
    }
};
