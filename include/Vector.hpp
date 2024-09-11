#pragma once

#include "../include/Point.hpp"

namespace vec {

struct Vector {
  float x;
  float y;

  Vector();
  Vector(float x, float y);
};

float dot(Vector &firstVec, Vector &secondVec);
float norm(Vector &firstVec);
Vector add(Vector &firstVec, Vector &secondVec);
Vector subtract(Vector &firstVec, Vector &secondVec);
Vector scalarProduct(Vector &firstVec, float scalar);
Vector projection(Vector &firstVec, Vector &secondVec);
Vector subtract(Point &firstPoint, Point &secondPoint);

} // namespace vec
