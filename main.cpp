#include <SFML/Graphics.hpp>
#include"GravitySource.h"
#include"Particle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "My Program");
    window.setFramerateLimit(60);

    GravitySource source(800, 500, 7000);

    Particle particle(600, 700, 4, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }


        window.clear();
        particle.update_physics(source);

        source.render(window);
        particle.render(window);
        //draw calls
        window.display();
    }

    return 0;
}