#pragma once
#include<cmath>
#include"vector2d.h"

class transform{
    Vector2 position;

    float rotation;

    Vector2 scale;

    transform()
    {
        position = Vector2(0.0f, 0.0f);
        rotation = 0.0f;
        scale = Vector2(1.0f, 1.0f);
    }

   transform(
        const Vector2& pos,
        float rot = 0.0f,
        const Vector2& scl = Vector2(1.0f, 1.0f)
    )
    {
        position = pos;
        rotation = rot;
        scale = scl;
    }
        Vector2 transformPoint(const Vector2& local) const
    {
        Vector2 scaled(
            local.x * scale.x,
            local.y * scale.y
        );

        float c = std::cos(rotation);
        float s = std::sin(rotation);

        Vector2 rotated(
            scaled.x * c - scaled.y * s,
            scaled.x * s + scaled.y * c
        );

        return rotated + position;
    }

    Vector2 transformDirection(const Vector2& dir) const
    {
        float c = std::cos(rotation);
        float s = std::sin(rotation);

        return Vector2(
            dir.x * c - dir.y * s,
            dir.x * s + dir.y * c
        );
    }

    void translateLocal(const Vector2& localDelta)
    {
        position += transformDirection(localDelta);
    }
};



