#pragma once
#include "vector2d.h"
#include "rigidbody.h"
#include "wheel.h"
#include "Suspension.h"
#include "TireModel.h"
#include "Drivetrain.h"
#include "Aerodynamics.h"

class F1Car
{
public:
    rigid_body body;

    Wheel wheels[4];
    Suspension suspension[4];
    TireModel tires[4];

    Drivetrain drivetrain;
    Aerodynamics aero;

    float wheelBase;
    float trackWidth;

    F1Car()
        : body(800.0f)
    {
        wheelBase = 3.6f;
        trackWidth = 1.8f;

        wheels[0] = Wheel(Vector2(-trackWidth * 0.5f,  wheelBase * 0.5f), 0.33f);
        wheels[1] = Wheel(Vector2( trackWidth * 0.5f,  wheelBase * 0.5f), 0.33f);
        wheels[2] = Wheel(Vector2(-trackWidth * 0.5f, -wheelBase * 0.5f), 0.33f);
        wheels[3] = Wheel(Vector2( trackWidth * 0.5f, -wheelBase * 0.5f), 0.33f);
    }

    void update(float dt)
    {
        Vector2 drag = aero.dragForce(body.velocity);
        body.apply_force(drag);

        float speed = body.velocity.magnitude();
        float down = aero.downforce(speed);
        float normalPerWheel = (body.mass * 9.81f + down) * 0.25f;

        float driveForce = drivetrain.computeLongitudinalForce(wheels[0].radius);

        for (int i = 0; i < 4; ++i)
        {
            Vector2 forward(0.0f, 1.0f);
            Vector2 lateral(1.0f, 0.0f);

            float longitudinalSlip = driveForce / normalPerWheel;
            Vector2 longForce = tires[i].longitudinalForce(longitudinalSlip, normalPerWheel);

            Vector2 latVel = Vector2(
                body.velocity.x * lateral.x,
                body.velocity.y * lateral.y
            );

            Vector2 latForce = tires[i].lateralForce(latVel, normalPerWheel);

            body.apply_force(longForce + latForce);
        }

        body.integrate(dt);
    }
};
