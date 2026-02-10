#pragma once
#include "vector2d.h"
#include <vector>

struct TelemetrySample
{
    Vector2 position;
    Vector2 velocity;
    float speed;
    float steering;
    float throttle;
    float brake;
};

class Telemetry
{
public:
    std::vector<TelemetrySample> samples;

    void record(
        const Vector2& position,
        const Vector2& velocity,
        float steering,
        float throttle,
        float brake
    )
    {
        TelemetrySample s;
        s.position = position;
        s.velocity = velocity;
        s.speed = velocity.magnitude();
        s.steering = steering;
        s.throttle = throttle;
        s.brake = brake;
        samples.push_back(s);
    }

    void clear()
    {
        samples.clear();
    }

    int size() const
    {
        return static_cast<int>(samples.size());
    }

    const TelemetrySample& get(int index) const
    {
        return samples[index];
    }
};
