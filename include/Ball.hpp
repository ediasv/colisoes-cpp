#pragma once

#include "Coordinate.hpp"
#include <SFML/Graphics/Color.hpp>

class Ball {
private:
  Coordinate m_position;
  Coordinate m_velocity;
  float m_radius;
  sf::Color m_color = sf::Color::Black;

public:
  Ball(Coordinate position, Coordinate velocity, float radius);
  void move();
  void setPosition(Coordinate position);
  Coordinate getPosition();
  Coordinate getVelocity();
};
