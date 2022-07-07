#include <SFML/Graphics.hpp>
#include"GravitySource.h"
#include"Particle.h"
#include <iostream>
#include <random>
#include <vector>


int whitetored(int n) {
    int r, g, b;
    r = 255;
    g = 255 - n;
    b = g;
    return r, g, b;
};


int main()
{
    

    sf::RenderWindow window(sf::VideoMode(1600, 1000), "SFML-Gravity");
    window.setFramerateLimit(60);

    GravitySource source(400, 500, 6000);
    GravitySource source2(1200, 500, 6000);
   
    Particle particle(600, 700, 4, 1);
    Particle particle2(600, 500, 4, 2);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }


        window.clear();

       /*
        int n = 0; // number of particles
        
        Particle* particle[4];
        for (int i = 0; i < sizeof(particle) / sizeof(*particle); i++) {
            particle[i] = new Particle(600 + i, 700 - 2*i, 4, 0);
            std::cout << particle[i] << std::endl;
            //Particle obj = particle[i];
            //obj.update_physics(source);
        } 

        for (int i = 0; i < sizeof(particle) / sizeof(*particle); i++)
            delete particle[i];  
        
        */
      
        particle.update_physics(source);
        particle.update_physics(source2);
        particle2.update_physics(source);
        particle2.update_physics(source2);
        source.render(window);
        source2.render(window);
        particle.render(window);
        particle2.render(window);
        
        // draw calls
        window.display();
    }

    return 0;
}
