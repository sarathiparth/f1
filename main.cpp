#include "physicsworld.h"
#include "f1car.h"
#include "unittest.h"

int main()
{
    UnitTests::runAll();

    PhysicsWorld world;
    F1Car car;

    world.addBody(car.body);

    for (int i = 0; i < 600; ++i)
    {
        car.drivetrain.setThrottle(0.6f);
        world.step();
    }

    return 0;
}
