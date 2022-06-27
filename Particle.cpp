#include"GravitySource.h"
#include"Particle.h"
#include <SFML/Graphics.hpp>


Particle::Particle(float pos_x, float pos_y, float vel_x, float vel_y)
{
    pos.x = pos_x;
    pos.y = pos_y;

    vel.x = vel_x;
    vel.y = vel_y;

    s.setPosition(pos);
    s.setFillColor(sf::Color::White);
    s.setRadius(8);
}

void Particle::render(sf::RenderWindow& wind)
{
    s.setPosition(pos);
    wind.draw(s);
}

void Particle::update_physics(GravitySource& s)
{
    float distance_x = s.get_pos().x - pos.x;
    float distance_y = s.get_pos().y - pos.y;

    float distance = sqrt(distance_x * distance_x + distance_y * distance_y);

    float distance_reciprocal = 1.f / distance;

    float normalized_x = distance_reciprocal * distance_x;
    float normalized_y = distance_reciprocal * distance_y;

    float reciprocal_square_dropoff = distance_reciprocal * distance_reciprocal;

    float acceleration_x = normalized_x * s.get_strength() * reciprocal_square_dropoff;
    float acceleration_y = normalized_y * s.get_strength() * reciprocal_square_dropoff;

    vel.x += acceleration_x;
    vel.y += acceleration_y;

    pos.x += vel.x;
    pos.y += vel.y;

}

