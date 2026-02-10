#pragma once
#include "vector2d.h"
#include <vector>

struct DebugLine
{
    Vector2 a;
    Vector2 b;
};

struct DebugCircle
{
    Vector2 center;
    float radius;
};

class DebugDraw
{
public:
    std::vector<DebugLine> lines;
    std::vector<DebugCircle> circles;

    void clear()
    {
        lines.clear();
        circles.clear();
    }

    void drawLine(const Vector2& a, const Vector2& b)
    {
        DebugLine l;
        l.a = a;
        l.b = b;
        lines.push_back(l);
    }

    void drawCircle(const Vector2& center, float radius)
    {
        DebugCircle c;
        c.center = center;
        c.radius = radius;
        circles.push_back(c);
    }
};
