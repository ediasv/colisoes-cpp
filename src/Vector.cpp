#include "../include/Vector.hpp"
#include <cmath>

vec::Vector::Vector() : x(0.f), y(0.f) {}
vec::Vector::Vector(float x, float y) : x(x), y(y) {}

float vec::dot(vec::Vector &firstVec, vec::Vector &secondVec) {
  return (firstVec.x * secondVec.x + firstVec.y * secondVec.y);
}

float vec::norm(vec::Vector &firstVec) {
  return (std::sqrt(firstVec.x * firstVec.x + firstVec.y * firstVec.y));
}

void vec::normalize(Vector &vector) {
  float normValue = norm(vector);
  vector = vec::scalarProduct(vector, 1 / normValue);
}

vec::Vector vec::add(vec::Vector &firstVec, vec::Vector &secondVec) {
  return vec::Vector(firstVec.x + secondVec.x, firstVec.y + secondVec.y);
}

vec::Vector vec::subtract(vec::Vector &firstVec, vec::Vector &secondVec) {
  return vec::Vector(firstVec.x - secondVec.x, firstVec.y - secondVec.y);
}
vec::Vector vec::scalarProduct(vec::Vector &firstVec, float scalar) {
  return vec::Vector(firstVec.x * scalar, firstVec.y * scalar);
}

vec::Vector vec::projection(vec::Vector &firstVec, vec::Vector &secondVec) {
  return vec::Vector(vec::scalarProduct(
      secondVec, vec::dot(firstVec, secondVec) / vec::norm(secondVec)));
}

vec::Vector vec::subtract(Point &firstPoint, Point &secondPoint) {
  return vec::Vector(firstPoint.x - secondPoint.x,
                     firstPoint.y - secondPoint.y);
}
