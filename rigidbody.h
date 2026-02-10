#pragma once
#include "vector2.h"
#include "integ.h"

class rigid_body
{
public:
    Vector2 position;
    Vector2 velocity;

    float mass;
    float inverse_mass;

    Vector2 force;

    rigid_body(float m = 1.0f)
        : position(0.0f, 0.0f),
          velocity(0.0f, 0.0f),
          mass(m),
          inverse_mass(m > 0.0f ? 1.0f / m : 0.0f),
          force(0.0f, 0.0f)
    {
    }

    void apply_force(const Vector2& f)
    {
        force += f;
    }

    void integrate(float dt)
    {
        if (dt <= 0.0f) return;

        Vector2 acc = force * inverse_mass;

        intg::semiImplicitEuler(
            position,
            velocity,
            acc,
            dt
        );

        force = Vector2(0.0f, 0.0f);
    }
};
