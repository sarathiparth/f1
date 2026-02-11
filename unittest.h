#pragma once
#include "vector2d.h"
#include "rigidbody.h"
#include "integ.h"
#include <cassert>
#include <cmath>
#include <iostream>

class UnitTests
{
private:
    static int testsPassed;
    static int testsRun;

    static void pass()
    {
        ++testsPassed;
    }

public:
    static void testVectorAdd()
    {
        ++testsRun;
        Vector2 a(1.0f, 2.0f);
        Vector2 b(3.0f, 4.0f);
        Vector2 c = a + b;

        assert(c.x == 4.0f && c.y == 6.0f);
        pass();
    }

    static void testVectorMagnitude()
    {
        ++testsRun;
        Vector2 a(3.0f, 4.0f);

        assert(std::abs(a.magnitude() - 5.0f) < 1e-5f);
        pass();
    }

    static void testIntegratorEuler()
    {
        ++testsRun;
        Vector2 pos(0.0f, 0.0f);
        Vector2 vel(0.0f, 0.0f);
        Vector2 acc(0.0f, 10.0f);

        intg::semiImplicitEuler(pos, vel, acc, 1.0f);

        assert(std::abs(vel.y - 10.0f) < 1e-5f);
        assert(std::abs(pos.y - 10.0f) < 1e-5f);
        pass();
    }

    static void testRigidBodyForce()
    {
        ++testsRun;
        rigid_body body(2.0f);
        body.apply_force(Vector2(0.0f, 10.0f));
        body.integrate(1.0f);

        assert(std::abs(body.velocity.y - 5.0f) < 1e-5f);
        pass();
    }

    static void testRigidBodyNoMass()
    {
        ++testsRun;
        rigid_body body(0.0f);
        body.apply_force(Vector2(0.0f, 10.0f));
        body.integrate(1.0f);

        assert(body.velocity.y == 0.0f);
        pass();
    }

    static void runAll()
    {
        std::cout << "Running Unit Tests...\n";

        testVectorAdd();
        testVectorMagnitude();
        testIntegratorEuler();
        testRigidBodyForce();
        testRigidBodyNoMass();

        std::cout << testsPassed << " / " << testsRun << " tests passed.\n\n";
    }
};

int UnitTests::testsPassed = 0;
int UnitTests::testsRun = 0;
