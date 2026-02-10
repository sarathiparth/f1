#pragma once
#include "vector2d.h"
#include <vector>

class Track
{
public:
    std::vector<Vector2> centerLine;
    std::vector<float> width;

    Track()
    {
    }

    Track(
        const std::vector<Vector2>& points,
        const std::vector<float>& widths
    )
    {
        centerLine = points;
        width = widths;
    }

    int segmentCount() const
    {
        return static_cast<int>(centerLine.size());
    }

    Vector2 getPoint(int index) const
    {
        return centerLine[index];
    }

    float getWidth(int index) const
    {
        return width[index];
    }

    Vector2 direction(int index) const
    {
        if (index + 1 >= segmentCount())
            return Vector2();

        Vector2 d = centerLine[index + 1] - centerLine[index];
        return d.normalized();
    }

    Vector2 normal(int index) const
    {
        Vector2 d = direction(index);
        return Vector2(-d.y, d.x);
    }

    bool isOnTrack(const Vector2& position, int index) const
    {
        Vector2 toCar = position - centerLine[index];
        float lateral = toCar.x * normal(index).x + toCar.y * normal(index).y;
        return std::abs(lateral) <= width[index] * 0.5f;
    }
};
