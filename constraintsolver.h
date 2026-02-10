#pragma once
#include "vector2d.h"
#include "rigidbody.h"

class ConstraintSolver
{
public:
    static void solveDistance(
        rigid_body& body,
        const Vector2& anchor,
        float restLength,
        float stiffness
    )
    {
        Vector2 delta = body.position - anchor;
        float dist = delta.magnitude();

        if (dist == 0.0f)
            return;

        float diff = (dist - restLength) / dist;
        Vector2 correction = delta * (stiffness * diff);

        body.position -= correction * body.inverse_mass;
    }

    static void solvePoint(
        rigid_body& body,
        const Vector2& target,
        float stiffness
    )
    {
        Vector2 delta = body.position - target;
        body.position -= delta * stiffness;
    }

    static void solveVelocity(
        rigid_body& body,
        const Vector2& normal
    )
    {
        float vn =
            body.velocity.x * normal.x +
            body.velocity.y * normal.y;

        if (vn < 0.0f)
            body.velocity -= normal * vn;
    }

    static void solvePenetration(
        rigid_body& body,
        const Vector2& normal,
        float penetration
    )
    {
        body.position -= normal * penetration;
    }
};
