#pragma once
#include "vector2d.h"

class Suspension
{
public:
    float restLength;
    float currentLength;
    float stiffness;
    float damping;

    Vector2 direction;
    Vector2 lastVelocity;

    Suspension()
    {
        restLength = 0.3f;
        currentLength = restLength;
        stiffness = 20000.0f;
        damping = 2500.0f;

        direction = Vector2(0.0f, -1.0f);
        lastVelocity = Vector2(0.0f, 0.0f);
    }

    Suspension(
        float rest,
        float stiff,
        float damp,
        const Vector2& dir
    )
    {
        restLength = rest;
        currentLength = rest;
        stiffness = stiff;
        damping = damp;

        direction = dir.normalized();
        lastVelocity = Vector2(0.0f, 0.0f);
    }

    Vector2 computeForce(
        float compression,
        float dt
    )
    {
        float springForce = stiffness * compression;
        float damperForce = damping * ((compression - currentLength) / dt);

        currentLength = compression;

        return direction * (springForce + damperForce);
    }
};
