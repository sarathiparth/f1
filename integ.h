#pragma once
#include "vector2d.h"

namespace intg
{

    inline void semiImplicitEuler(
        Vector2& position,
        Vector2& velocity,
        const Vector2& acceleration,
        float dt
    )
    {
        velocity += acceleration * dt;
        position += velocity * dt;
    }

    inline void rungeKutta4(
        Vector2& position,
        Vector2& velocity,
        const Vector2& acceleration,
        float dt
    )
    {
        Vector2 k1_v = acceleration;
        Vector2 k1_x = velocity;

        Vector2 k2_v = acceleration;
        Vector2 k2_x = velocity + k1_v * (dt * 0.5f);

        Vector2 k3_v = acceleration;
        Vector2 k3_x = velocity + k2_v * (dt * 0.5f);

        Vector2 k4_v = acceleration;
        Vector2 k4_x = velocity + k3_v * dt;

        velocity += (k1_v + k2_v * 2.0f + k3_v * 2.0f + k4_v) * (dt / 6.0f);
        position += (k1_x + k2_x * 2.0f + k3_x * 2.0f + k4_x) * (dt / 6.0f);
    }


    template <typename IntegratorFunc>
    inline void substep(
        IntegratorFunc integrator,
        Vector2& position,
        Vector2& velocity,
        const Vector2& acceleration,
        float dt,
        int steps
    )
    {
        if (steps <= 0) return;

        float subDt = dt / steps;

        for (int i = 0; i < steps; ++i)
        {
            integrator(position, velocity, acceleration, subDt);
        }
    }
}
