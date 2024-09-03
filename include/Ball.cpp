#include "Ball.hpp"
#include "Constants.hpp"
#include "Coordinate.hpp"
#include <SFML/Graphics/Color.hpp>

void Ball::move() {
  this->position.x += this->velocity.x;
  this->position.y += this->velocity.y;

  // check for wall colision;
  // top
  if (this->position.y - this->radius <= 0) {
    this->velocity.y *= -1;
  }
  // bottom
  if (this->position.y + this->radius >= WIN_HEIGHT) {
    this->velocity.y *= -1;
  }
  // left
  if (this->position.x - this->radius <= 0) {
    this->velocity.x *= -1;
  }
  // right
  if (this->position.x + this->radius >= WIN_WIDTH) {
    this->velocity.x *= -1;
  }
}
