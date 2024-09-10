#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

const unsigned short int width = 1200;
const unsigned short int height = 700;
const float cr = 0.6;

class Ball {
public:
  float vx, vy;
  float x, y;
  float radius;

public:
  Ball();
  void move();
  sf::CircleShape draw();

  friend bool hasOverlap(std::vector<Ball> &balls, int i, int j);
  friend float displace(Ball &firstBall, Ball &secondBall);
  friend float sqDistance(Ball &firstBall, Ball &secondBall);
};

class BallVector {
public:
  const short int n_balls = 100;
  std::vector<Ball> balls;

  BallVector();
};
