#include "../include/Vector.hpp"
#include <cmath>

Vector::Vector() {}
Vector::Vector(float x, float y) : x(x), y(y) {}

Vector projection(Vector &firstVec, Vector &secondVec) {
  return scalarProduct(secondVec, dot(firstVec, secondVec) /
                                      (norm(secondVec) * norm(secondVec)));
}

float dot(Vector &firstVec, Vector &secondVec) {
  return firstVec.x * secondVec.x + firstVec.y * secondVec.y;
}

Vector add(Vector &firstVec, Vector &secondVec) {
  Vector sum;
  sum.x = firstVec.x + secondVec.x;
  sum.y = firstVec.y + secondVec.y;
  return sum;
}

Vector subtract(Vector &firstVec, Vector &secondVec) {
  Vector dif;
  dif.x = firstVec.x - secondVec.x;
  dif.y = firstVec.y - secondVec.y;
  return dif;
}

float norm(Vector &firstVec) {
  return std::sqrt(firstVec.x * firstVec.x + firstVec.y * firstVec.y);
}

Vector scalarProduct(Vector &firstVec, float scalar) {
  Vector result(firstVec.x * scalar, firstVec.y * scalar);
  return result;
}
