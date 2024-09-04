#include "Ball.hpp"
#include "Coordinate.hpp"
#include "MyRandom.hpp"
#include <SFML/Graphics/CircleShape.hpp>

Ball::Ball() {
  this->m_velocity = Coordinate(randFloat(0, 15), randFloat(0, 15));
  this->m_shape.setRadius(randFloat(10, 50));
}
