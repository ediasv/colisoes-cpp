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
  const short int n_balls = 20;
  std::vector<Ball> balls;

  BallVector();
};

float sqDistance(Ball &firstBall, Ball &secondBall);
bool hasOverlap(std::vector<Ball> &balls, int i, int j);
float qDisplace(Ball &firstBall, Ball &secondBall);
void displace(Ball &firstBall, Ball &secondBall);
void colide(Ball &firstBall, Ball &secondBall);
