#pragma once
#include"vector.h"

namespace intg{

    inline void semiImplicitEuler(
        vector3& position,          
        vector3& velocity,          
        const vector3& acceleration,
        float dt                    
    )
    {
        position += velocity * dt;
        velocity += acceleration * dt;
    }
    inline void semiImplicitEuler(
        vector3& position,
        vector3& velocity,
        const vector3& acceleration,
        float dt
    )
    {
        velocity += acceleration * dt;
        position += velocity * dt;
    }
    inline void verlet(
        vector3& position,
        vector3& previousPosition,
        const vector3& acceleration,
        float dt
    )
    {
        vector3 temp = position;
        position = position + (position - previousPosition)
                   + acceleration * (dt * dt);
        previousPosition = temp;
    }

     inline void rungeKutta4(
    vector3& position,
    vector3& velocity,
    const vector3& acceleration,
    float dt
)
{
    vector3 k1_v = acceleration;
    vector3 k1_x = velocity;

    vector3 k2_v = acceleration;
    vector3 k2_x = velocity + k1_v * (dt * 0.5f);

    vector3 k3_v = acceleration;
    vector3 k3_x = velocity + k2_v * (dt * 0.5f);

    vector3 k4_v = acceleration;
    vector3 k4_x = velocity + k3_v * dt;

    velocity += (k1_v
               + k2_v * 2.0f
               + k3_v * 2.0f
               + k4_v) * (dt / 6.0f);

    position += (k1_x
               + k2_x * 2.0f
               + k3_x * 2.0f
               + k4_x) * (dt / 6.0f);
}

template <typename IntegratorFunc>
    inline void substep(
        IntegratorFunc integrator,
        vector3& position,
        vector3& velocity,
        const vector3& acceleration,
        float dt,
        int steps
    )
    {
        float subDt = dt / steps;

        for (int i = 0; i < steps; ++i)
        {
            integrator(position, velocity, acceleration, subDt);
        }
    }
}




