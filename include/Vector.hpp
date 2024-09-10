#pragma once

class Vector {
public:
  float x;
  float y;

  Vector();
  Vector(float x, float y);

  friend Vector projection(Vector &firstVec, Vector &secondVec);
  friend float dot(Vector &firstVec, Vector &secondVec);
  friend Vector add(Vector &firstVec, Vector &secondVec);
  friend Vector subtract(Vector &firstVec, Vector &secondVec);
  friend float norm(Vector &firstVec);
  friend Vector scalarProduct(Vector &firstVec, float scalar);
};
