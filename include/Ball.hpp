#pragma once

#include "Coordinate.hpp"
#include <SFML/Graphics/Color.hpp>

class Ball {
private:
  Coordinate position;
  Coordinate velocity;
  float radius;
  sf::Color color = sf::Color::Black;

public:
  void move();
  void setPosition(Coordinate position);
  Coordinate getPosition();
  Coordinate getVelocity();
  friend void colide(Ball firstBall, Ball secondBall);
};
