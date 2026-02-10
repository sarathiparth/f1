#pragma once
#include "vector2d.h"
#include "rigidbody.h"
#include "integ.h"
#include <cassert>
#include <cmath>

class UnitTests
{
public:
    static void testVectorAdd()
    {
        Vector2 a(1.0f, 2.0f);
        Vector2 b(3.0f, 4.0f);
        Vector2 c = a + b;
        assert(c.x == 4.0f && c.y == 6.0f);
    }

    static void testVectorMagnitude()
    {
        Vector2 a(3.0f, 4.0f);
        assert(std::abs(a.magnitude() - 5.0f) < 1e-5f);
    }

    static void testIntegratorEuler()
    {
        Vector2 pos(0.0f, 0.0f);
        Vector2 vel(0.0f, 0.0f);
        Vector2 acc(0.0f, 10.0f);

        intg::semiImplicitEuler(pos, vel, acc, 1.0f);

        assert(vel.y == 10.0f);
        assert(pos.y == 10.0f);
    }

    static void testRigidBodyForce()
    {
        rigid_body body(2.0f);
        body.apply_force(Vector2(0.0f, 10.0f));
        body.integrate(1.0f);

        assert(std::abs(body.velocity.y - 5.0f) < 1e-5f);
    }

    static void testRigidBodyNoMass()
    {
        rigid_body body(0.0f);
        body.apply_force(Vector2(0.0f, 10.0f));
        body.integrate(1.0f);

        assert(body.velocity.y == 0.0f);
    }

    static void runAll()
    {
        testVectorAdd();
        testVectorMagnitude();
        testIntegratorEuler();
        testRigidBodyForce();
        testRigidBodyNoMass();
    }
};
