#include "Ball.hpp"
#include "Constants.hpp"
#include "Coordinate.hpp"
#include <SFML/Graphics/Color.hpp>

Ball::Ball(Coordinate position, Coordinate velocity, float radius)
    : m_position(position), m_velocity(velocity), m_radius(radius) {}

void Ball::move() {
  this->m_position.x += this->m_velocity.x;
  this->m_position.y += this->m_velocity.y;

  // check for wall colision;
  // top
  if (this->m_position.y - this->m_radius <= 0) {
    this->m_velocity.y *= -1;
  }
  // bottom
  if (this->m_position.y + this->m_radius >= WIN_HEIGHT) {
    this->m_velocity.y *= -1;
  }
  // left
  if (this->m_position.x - this->m_radius <= 0) {
    this->m_velocity.x *= -1;
  }
  // right
  if (this->m_position.x + this->m_radius >= WIN_WIDTH) {
    this->m_velocity.x *= -1;
  }
}

void Ball::setPosition(Coordinate position) {
  this->m_position.x = position.x;
  this->m_position.y = position.y;
}

Coordinate Ball::getPosition() { return this->m_position; }

Coordinate Ball::getVelocity() { return this->m_velocity; }
