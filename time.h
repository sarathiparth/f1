#pragma once

class Time
{
public:
    static constexpr float FIXED_DT = 0.0166667f;

    static float time;

    static float deltaTime;

    static void reset()
    {
        time = 0.0f;
        deltaTime = FIXED_DT;
    }

    static void step()
    {
        deltaTime = FIXED_DT;
        time += deltaTime;
    }
};
