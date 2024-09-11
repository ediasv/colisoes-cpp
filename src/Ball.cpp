#include "../include/Ball.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

Ball::Ball() : radius(10.f) {

  this->position.x = rand() % (int)(width - 2 * this->radius);
  this->position.y = rand() % (int)(height - 2 * this->radius);

  this->velocity.x = (rand() % 41) - 20;
  this->velocity.y = (rand() % 41) - 20;
}

void Ball::move() {
  this->position.x += this->velocity.x;
  this->position.y += this->velocity.y;

  // check wall collision
  if (this->position.x <= 0) {
    this->position.x = 0;
    this->velocity.x *= -1 * cr;

  } else if (this->position.x + 2 * this->radius >= width) {
    this->position.x = width - 2 * this->radius;
    this->velocity.x *= -1 * cr;
  }

  if (this->position.y <= 0) {
    this->position.y = 0;
    this->velocity.y *= -1 * cr;

  } else if (this->position.y + 2 * this->radius >= height) {
    this->position.y = height - 2 * this->radius;
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

BallVector::BallVector() {
  for (int i = 0; i < this->n_balls; i++) {
    Ball ball = Ball();
    this->balls.push_back(ball);
  }
}

float distance(Ball &ball, Ball &target) {
  float dx = ball.position.x - target.position.x;
  float dy = ball.position.y - target.position.y;
  return sqrt(dx * dx + dy * dy);
}

bool hasOverlap(Ball &ball, Ball &target) {
  return (distance(ball, target) <= (ball.radius + target.radius));
}

float qOverlap(Ball &ball, Ball &target) {
  return ball.radius + target.radius - distance(ball, target);
}

void displace(Ball &ball, Ball &target) {
  // move both balls so that they only touch each other
  float overlap = qOverlap(ball, target);

  vec::Vector collisionVec(vec::subtract(ball.position, target.position));

  vec::normalize(collisionVec);

  ball.position.x += collisionVec.x * overlap * 0.5;
  ball.position.y += collisionVec.y * overlap * 0.5;

  target.position.x -= collisionVec.x * overlap * 0.5;
  target.position.y -= collisionVec.y * overlap * 0.5;
}

void colide(Ball &ball, Ball &target) {
  // change the velocity from each ball accordingly
}
