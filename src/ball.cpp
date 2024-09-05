#include "../include/ball.hpp"
#include <random>

Ball::Ball() : x(width / 2.f), y(heigth / 2.f), radius(5.f) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dist(5, 20);

  this->vx = dist(gen);
  this->vy = dist(gen);
}

void Ball::move() {
  this->x += this->vx;
  this->y += this->vy;

  // check wall collision
  if (this->x - this->radius <= 0) {
    this->x = 0;
    this->vx *= -1;

  } else if (this->x + this->radius >= width) {
    this->x = width - this->radius;
    this->vx *= -1;
  }

  if (this->y - this->radius <= 0) {
    this->y = 0;
    this->vy *= -1;

  } else if (this->y + this->radius >= heigth) {
    this->y = heigth - this->radius;
    this->vy *= -1;
  }
}

sf::CircleShape Ball::draw() {
  sf::CircleShape ball;
  ball.setRadius(this->radius);
  ball.setFillColor(sf::Color::White);
  ball.setPosition(this->x, this->y);

  return ball;
}

float sqDistance(Ball &firstBall, Ball &secondBall) {
  float dx = firstBall.x - secondBall.x;
  float dy = firstBall.y - secondBall.y;
  return (dx * dx + dy * dy);
}

bool hasOverlap(std::vector<Ball> &balls, int &i, int &j) {
  float sqRadius = balls.at(i).radius + balls.at(j).radius;
  sqRadius *= sqRadius;
  if (sqDistance(balls.at(i), balls.at(j)) <= sqRadius) {
    return true;
  }
  return false;
}

BallVector::BallVector() {
  Ball ball = Ball();
  for (int i = 0; i < this->n_balls; i++) {
    this->balls.push_back(ball);
  }
}
