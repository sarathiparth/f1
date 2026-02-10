#pragma once

struct Input
{
    float throttle;
    float brake;
    float steering;

    Input()
    {
        throttle = 0.0f;
        brake = 0.0f;
        steering = 0.0f;
    }

    Input(float t, float b, float s)
    {
        throttle = t;
        brake = b;
        steering = s;
    }

    void clear()
    {
        throttle = 0.0f;
        brake = 0.0f;
        steering = 0.0f;
    }
};
