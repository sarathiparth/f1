#pragma once
#include <cmath>
#include "Vector2.h"

namespace MathUtils
{
    constexpr float PI = 3.14159265358979323846f;
    constexpr float TWO_PI = 2.0f * PI;
    constexpr float EPSILON = 1e-6f;

    inline float degToRad(float degrees)
    {
        return degrees * (PI / 180.0f);
    }

    inline float radToDeg(float radians)

    {
        return radians * (180.0f / PI);
    }

    inline float clamp(float value, float minVal, float maxVal)
    {
        if (value < minVal) return minVal;
        if (value > maxVal) return maxVal;
        return value;
    }

    inline float lerp(float a, float b, float t)
    {
        return a + (b - a) * t;
    }

    inline bool nearlyEqual(float a, float b, float eps = EPSILON)
    {
        return std::fabs(a - b) < eps;
    }

    inline Vector2 clampMagnitude(const Vector2& v, float maxLength)
    {
        float magSq = v.magnitudesq();
        float maxSq = maxLength * maxLength;

        if (magSq > maxSq)
            return v.normalized() * maxLength;

        return v;
    }
}
