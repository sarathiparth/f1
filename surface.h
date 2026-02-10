#pragma once
#include "vector2d.h"

class Surface
{
public:
    float friction;
    float grip;
    float rollingResistance;
    float dragMultiplier;

    Surface()
    {
        friction = 1.0f;
        grip = 1.0f;
        rollingResistance = 0.015f;
        dragMultiplier = 1.0f;
    }

    Surface(
        float fric,
        float g,
        float rr,
        float drag
    )
    {
        friction = fric;
        grip = g;
        rollingResistance = rr;
        dragMultiplier = drag;
    }

    float applyGrip(float baseGrip) const
    {
        return baseGrip * grip * friction;
    }

    float applyRollingResistance(float normalForce) const
    {
        return normalForce * rollingResistance;
    }

    Vector2 applySurfaceDrag(const Vector2& velocity) const
    {
        return velocity * -dragMultiplier;
    }
};
