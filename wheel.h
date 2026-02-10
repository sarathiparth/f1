
#pragma once
#include "vector2d.h"

class Wheel
{
public:
    Vector2 localPosition;
    Vector2 worldPosition;

    float radius;
    float angularVelocity;
    float rotation;

    bool grounded;

    Wheel()
    {
        localPosition = Vector2();
        worldPosition = Vector2();
        radius = 0.35f;
        angularVelocity = 0.0f;
        rotation = 0.0f;
        grounded = false;
    }

    Wheel(const Vector2& localPos, float r)
    {
        localPosition = localPos;
        worldPosition = Vector2();
        radius = r;
        angularVelocity = 0.0f;
        rotation = 0.0f;
        grounded = false;
    }
    void updaterotation(float dt){
        rotation += angularVelocity *dt;
    }
};


    

