#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

namespace geom {

struct Vec2 {
  float x, y;

  Vec2(float x = 0, float y = 0) : x(x), y(y) {}

  Vec2 operator+(const Vec2 &otherVec2) const; // sum of vectors
  Vec2 operator-(const Vec2 &otherVec2) const; // subtraction of vectors
  Vec2 scalarProduct(float scalar) const;
  Vec2 normalize() const;
  float magnitude() const;
};

struct Point2 {
  float x, y;

  Point2(float x = 0, float y = 0) : x(x), y(y) {}

  // Diff between this point and other point, returns a Vec2
  Vec2 operator-(const Point2 &other) const;

  // Sum between this point and a vector, returns a Point2
  Point2 operator+(const Vec2 &vec) const;
};

struct Circle {
  Point2 position;
  float radius;
  Vec2 velocity;

  Circle(float radius = 0) : radius(radius) {}

  void move();
};

struct Circles {
  const int n_balls;
  std::vector<Circle> balls;

  Circles(int n_balls) : n_balls(n_balls) {}
};

// Returns the distance between firstPoint2 and secondPoint2
float distance(const Point2 &firstPoint, const Point2 &secondPoint);

// Returns wheter firstCircle collides with secondCircle
bool hasCollision(const Circle &firstCircle, const Circle &secondCircle);

/*
 * Moves firstCircle and secondCircle to the position of intersection.
 * Each cirlce is displaced by half the overlap size
 */
void displace(Circle &firstCircle, Circle &secondCircle);

// Solves collision between firstCircle and secondCircle
void solveCollision(Circle &firstCircle, Circle &secondCircle);

// Returns the amount of overlap between firstCircle and secondCircle
float qOverlap(const Circle &firstCircle, const Circle &secondCircle);

// Returns the dot product between firstVec and secondVec
float dot(const Vec2 &firstVec, const Vec2 &secondVec);

/*
 * Returns the Vec2 that results of the projection
 * of firstVec onto secondVec
 */
Vec2 projection(const Vec2 &firstVec, const Vec2 &secondVec);

} // namespace geom
