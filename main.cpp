#include <SFML/Graphics.hpp>
#include <iostream>
#include "physicsworld.h"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({1000, 700}),
        "Physics Engine Debug"
    );

    PhysicsWorld world;
    rigid_body body(5.0f, 120.0f, 50.0f);

    world.addBody(body);

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        world.step();

        window.clear(sf::Color::Black);

        sf::RectangleShape rect(sf::Vector2f(body.width, body.height));
        rect.setOrigin({body.width / 2.f, body.height / 2.f});
        rect.setPosition({body.position.x, 700.f - body.position.y});
        rect.setRotation(sf::radians(body.rotation));
        rect.setFillColor(sf::Color::Green);

        window.draw(rect);
        window.display();
    }

    return 0;
}
