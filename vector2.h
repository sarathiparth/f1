#pragma once
#include <cmath>

class Vector2
{
public:
    float x;
    float y;

    Vector2(float x = 0.0f, float y = 0.0f)
    {
        this->x = x;
        this->y = y;
    }

    Vector2 operator + (const Vector2& v) const
    {
        return Vector2(x + v.x, y + v.y);
    }

    Vector2 operator - (const Vector2& v) const
    {
        return Vector2(x - v.x, y - v.y);
    }

    Vector2 operator * (float s) const
    {
        return Vector2(x * s, y * s);
    }

    Vector2 operator / (float s) const
    {
        return Vector2(x / s, y / s);
    }

    Vector2& operator += (const Vector2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2& operator -= (const Vector2& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector2& operator *= (float s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vector2& operator /= (float s)
    {
        x /= s;
        y /= s;
        return *this;
    }

    float magnitude() const
    {
        return std::sqrt(x * x + y * y);
    }

    float magnitudesq() const
    {
        return x * x + y * y;
    }

    Vector2 normalized() const
    {
        float m = magnitude();
        if (m == 0.0f)
            return Vector2(0, 0);

        return Vector2(x / m, y / m);
    }

    float dot(const Vector2& v) const
    {
        return x * v.x + y * v.y;
    }

    Vector2 perpendicular() const
    {
        return Vector2(-y, x);
    }

    float angle() const
    {
    return std::atan2(y, x);
    }

    static Vector2 fromAngle(float radians)
    {
    return Vector2(std::cos(radians), std::sin(radians));
    }

};
