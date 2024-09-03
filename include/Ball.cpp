#include "Ball.hpp"
#include "Coordinate.hpp"
#include "MyRandom.hpp"

Ball::Ball() {
  this->m_velocity = Coordinate(randFloat(0, 15), randFloat(0, 15));
  this->m_shape.setRadius(randFloat(10, 50));
}
