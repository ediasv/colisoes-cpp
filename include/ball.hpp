#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <vector>

const unsigned short int width = 1200;
const unsigned short int heigth = 700;

struct Ball {
  float m_vx, m_vy;
  float m_x, m_y;
  float radius;
  sf::CircleShape shape;
  Ball();
  void move();
  friend bool hasOverlap(std::vector<Ball> &balls, int i, int j);
  friend void displace(Ball firstBall, Ball secondBall);
  friend float distance(Ball firstBall, Ball secondBall);
};
