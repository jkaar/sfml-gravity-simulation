#ifndef PARTICLE_H
#define PARTICLE_H
#include <SFML/Graphics.hpp>
#include"GravitySource.h"


class Particle
{
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::CircleShape s;


public:

    Particle(float pos_x, float pos_y, float vel_x, float vel_y);

    void render(sf::RenderWindow& wind);
    
    void update_physics(GravitySource& s);
    
};

#endif