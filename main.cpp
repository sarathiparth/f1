#include <SFML/Graphics.hpp>
#include "physicsworld.h"
#include "f1car.h"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "F1 Physics Engine"
    );

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Blue);
        window.display();
    }

    return 0;
}
