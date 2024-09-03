#pragma once

#include "Coordinate.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

class Ball {
private:
  Coordinate m_velocity;
  sf::CircleShape m_shape;

public:
  Ball();
};
