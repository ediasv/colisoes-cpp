#pragma once

#include "Coordinate.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

struct Ball {
  Coordinate m_velocity;
  sf::CircleShape m_shape;
  Ball();
  friend Ball &makeBalls(int nBalls);
};
