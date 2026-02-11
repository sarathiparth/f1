#pragma once
#include "vector2d.h"
#include "rigidbody.h"
#include "constraintSolver.h"
#include <vector>

class PhysicsWorld
{
public:
    std::vector<rigid_body*> bodies;

    Vector2 gravity;

    float fixedDt;
    int solverIterations;

    PhysicsWorld()
    {
        gravity = Vector2(0.0f, -9.81f);
        fixedDt = 1.0f / 60.0f;
        solverIterations = 8;
    }

    void addBody(rigid_body& body)
    {
        bodies.push_back(&body);
    }

    void step()
    {
        for (auto body : bodies)
        {
            if (body->inverse_mass == 0.0f)
                continue;

            body->apply_force(gravity * body->mass);
        }

        for (auto body : bodies)
        {
            body->integrate(fixedDt);
        }

        for (int i = 0; i < solverIterations; ++i)
        {
            solveConstraints();
        }
    }

private:

    void solveConstraints()
    {
        for (auto body : bodies)
        {
            if (body->position.y < 0.0f)
            {
                float penetration = -body->position.y;

                ConstraintSolver::solvePenetration(
                    *body,
                    Vector2(0.0f, 1.0f),
                    penetration
                );

                ConstraintSolver::solveVelocity(
                    *body,
                    Vector2(0.0f, 1.0f)
                );
            }
        }
    }
};
