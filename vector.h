#pragma once
#include <cmath>

class vector3
{
public:
    float x;
    float y;
    float z;

    vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    vector3 operator + (const vector3& v) const
    {
        return vector3(x + v.x, y + v.y, z + v.z);
    }

    vector3 operator - (const vector3& v) const
    {
        return vector3(x - v.x, y - v.y, z - v.z);
    }

    vector3 operator * (float s) const
    {
        return vector3(x * s, y * s, z * s);
    }

    vector3 operator / (float s) const
    {
        return vector3(x / s, y / s, z / s);
    }

    vector3& operator += (const vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    vector3& operator -= (const vector3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    vector3& operator *= (float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    vector3& operator /= (float s)
    {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }

    float magnitude() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    float magnitudesq() const
    {
        return x * x + y * y + z * z;
    }

    vector3 normalized() const
    {
        float m = magnitude();
        if (m == 0.0f)
            return vector3(0, 0, 0);

        return vector3(x / m, y / m, z / m);
    }

    float dot(const vector3& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    vector3 cross(const vector3& v) const
    {
        return vector3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }
};
