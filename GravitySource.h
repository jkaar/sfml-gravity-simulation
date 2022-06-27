#ifndef GRAVITY_SOURCE_H
#define GRAVITY_SOURCE_H
#include <SFML/Graphics.hpp>

class GravitySource
{
    sf::Vector2f pos;
    float strength;
    sf::CircleShape s;


public:
    GravitySource(float pos_x, float pos_y, float strength);

    void render(sf::RenderWindow& wind);
    
    sf::Vector2f get_pos();
    
    float get_strength();
};

#endif
