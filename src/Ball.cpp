#include "../include/Ball.hpp"
#include <cmath>
#include <random>

Ball::Ball() : position(width / 2.f, width / 2.f), radius(5.f) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dist(-20, 20);

  this->velocity.x = dist(gen);

  this->velocity.y = dist(gen);
}

void Ball::move() {
  this->position.x += this->velocity.x;
  this->position.y += this->velocity.y;

  // check wall collision
  if (this->position.x - this->radius <= 0) {
    this->position.x = this->radius;
    this->velocity.x *= -1 * cr;

  } else if (this->position.x + this->radius >= width) {
    this->position.x = width - this->radius;
    this->velocity.x *= -1 * cr;
  }

  if (this->position.y - this->radius <= 0) {
    this->position.y = this->radius;
    this->velocity.y *= -1 * cr;

  } else if (this->position.y + this->radius >= height) {
    this->position.y = height - this->radius;
    this->velocity.y *= -1 * cr;
  }
}

sf::CircleShape Ball::draw() {
  sf::CircleShape ball;
  ball.setRadius(this->radius);
  ball.setFillColor(sf::Color::White);
  ball.setPosition(this->position.x, this->position.y);

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
  float dx = firstBall.position.x - secondBall.position.x;
  float dy = firstBall.position.y - secondBall.position.y;
  return (dx * dx + dy * dy);
}

BallVector::BallVector() {
  for (int i = 0; i < this->n_balls; i++) {
    Ball ball = Ball();
    this->balls.push_back(ball);
  }
}
