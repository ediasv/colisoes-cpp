#pragma once

#include "Point.hpp"
#include "Vector.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

const unsigned short int width = 1200;
const unsigned short int height = 700;
const float cr = 0.6;

struct Ball {
  vec::Vector velocity;
  Point position;
  float radius;

  Ball();
  void move();
  sf::CircleShape draw();
};

struct BallVector {
  const short int n_balls = 30;
  std::vector<Ball> balls;

  BallVector();
};

float distance(Ball &ball, Ball &target);
bool hasOverlap(Ball &ball, Ball &target);
float qOverlap(Ball &ball, Ball &target);
void displace(Ball &ball, Ball &target);
void colide(Ball &ball, Ball &target);
