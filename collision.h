#pragma once
#include "vector2d.h"
#include "rigidbody.h"
#include <cmath>

struct CollisionManifold
{
    bool colliding;
    Vector2 normal;
    float penetration;

    CollisionManifold()
    {
        colliding = false;
        normal = Vector2();
        penetration = 0.0f;
    }
};

class Collision2D
{
public:
    static CollisionManifold circleCircle(
        const Vector2& posA,
        float radiusA,
        const Vector2& posB,
        float radiusB
    )
    {
        CollisionManifold m;

        Vector2 diff = posB - posA;
        float distSq = diff.x * diff.x + diff.y * diff.y;
        float r = radiusA + radiusB;

        if (distSq >= r * r)
            return m;

        float dist = std::sqrt(distSq);

        m.colliding = true;

        if (dist != 0.0f)
        {
            m.normal = diff * (1.0f / dist);
            m.penetration = r - dist;
        }
        else
        {
            m.normal = Vector2(1.0f, 0.0f);
            m.penetration = r;
        }

        return m;
    }

    static void resolve(
        rigid_body& body,
        const CollisionManifold& m
    )
    {
        if (!m.colliding)
            return;

        body.position -= m.normal * m.penetration;

        float vn = body.velocity.x * m.normal.x +
                   body.velocity.y * m.normal.y;

        if (vn < 0.0f)
            body.velocity -= m.normal * vn;
    }
};

