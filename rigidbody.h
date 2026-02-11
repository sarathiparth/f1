#pragma once
#include "vector2d.h"
#include <cmath>

class rigid_body
{
public:
    Vector2 position;
    Vector2 velocity;
    Vector2 force;

    float mass;
    float inverse_mass;

    float rotation;
    float angularVelocity;
    float torque;

    float inertia;
    float inverse_inertia;

    float width;
    float height;

    rigid_body(float m = 1.0f, float w = 120.0f, float h = 50.0f)
    {
        position = Vector2(500.0f, 600.0f);   // START HIGH
        velocity = Vector2(0.0f, 0.0f);
        force = Vector2(0.0f, 0.0f);

        mass = m;
        inverse_mass = (m > 0.0f) ? 1.0f / m : 0.0f;

        width = w;
        height = h;

        inertia = (m * (w * w + h * h)) / 12.0f;
        inverse_inertia = (inertia > 0.0f) ? 1.0f / inertia : 0.0f;

        rotation = 0.0f;
        angularVelocity = 0.0f;
        torque = 0.0f;
    }

    void apply_force(const Vector2& f)
    {
        force += f;
    }

    void integrate(float dt)
    {
        if (inverse_mass == 0.0f)
            return;

        Vector2 acceleration = force * inverse_mass;
        velocity += acceleration * dt;
        position += velocity * dt;

        force = Vector2(0.0f, 0.0f);
    }
};
