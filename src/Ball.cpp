#include "../include/Ball.hpp"
#include <cmath>
#include <random>

Ball::Ball() : x(width / 2.f), y(height / 2.f), radius(5.f) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dist(-20, 20);

  this->vx = dist(gen);
  this->vy = dist(gen);
}

void Ball::move() {
  this->x += this->vx;
  this->y += this->vy;

  // check wall collision
  if (this->x - this->radius <= 0) {
    this->x = this->radius;
    this->vx *= -1 * cr;

  } else if (this->x + this->radius >= width) {
    this->x = width - this->radius;
    this->vx *= -1 * cr;
  }

  if (this->y - this->radius <= 0) {
    this->y = this->radius;
    this->vy *= -1 * cr;

  } else if (this->y + this->radius >= height) {
    this->y = height - this->radius;
    this->vy *= -1 * cr;
  }
}

sf::CircleShape Ball::draw() {
  sf::CircleShape ball;
  ball.setRadius(this->radius);
  ball.setFillColor(sf::Color::White);
  ball.setPosition(this->x, this->y);

  return ball;
}

bool hasOverlap(std::vector<Ball> &balls, int i, int j) {
  float sqRadius = balls.at(i).radius + balls.at(j).radius;
  sqRadius *= sqRadius;
  if (sqDistance(balls.at(i), balls.at(j)) <= sqRadius) {
    return true;
  }
  return false;
}

float displace(Ball &firstBall, Ball &secondBall) {
  return 0.5 * (sqrt(sqDistance(firstBall, secondBall)) - firstBall.radius -
                secondBall.radius);
}

float sqDistance(Ball &firstBall, Ball &secondBall) {
  float dx = firstBall.x - secondBall.x;
  float dy = firstBall.y - secondBall.y;
  return (dx * dx + dy * dy);
}

BallVector::BallVector() {
  for (int i = 0; i < this->n_balls; i++) {
    Ball ball = Ball();
    this->balls.push_back(ball);
  }
}
