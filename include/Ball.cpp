#include "Ball.hpp"
#include "Constants.hpp"
#include "Coordinate.hpp"
#include <SFML/Graphics/Color.hpp>

void Ball::move() {
  this->position.x += this->velocity.x;
  this->position.y += this->velocity.y;

  // check for wall colision;
  // top
  if (this->position.y >)
  // bottom
  // left
  // right
}
