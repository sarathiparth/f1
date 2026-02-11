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
}
