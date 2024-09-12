#include "../include/Geometry.hpp"
#include <cmath>

using namespace geom;

/*
 * =========================== Vec2 implementation ===========================
 */

Vec2 Vec2::operator+(const Vec2 &otherVec2) const {
  return Vec2(this->x + otherVec2.x, this->y + otherVec2.y);
}

Vec2 Vec2::operator-(const Vec2 &otherVec2) const {
  return Vec2(this->x - otherVec2.x, this->y - otherVec2.y);
}

Vec2 Vec2::scalarProduct(float scalar) const {
  return Vec2(this->x * scalar, this->y * scalar);
}

Vec2 Vec2::normalize() const {
  float thisNorm = this->magnitude();
  return Vec2(this->x / thisNorm, this->y / thisNorm);
}

float Vec2::magnitude() const {
  return std::sqrt(this->x * this->x + this->y * this->y);
}

/*
 * ======================== Point2 implementation ========================
 */

Vec2 Point2::operator-(const Point2 &other) const {
  return Vec2(this->x - other.x, this->y - other.y);
}

Point2 Point2::operator+(const Vec2 &vec) const {
  return Point2(this->x + vec.x, this->y + vec.y);
}

/*
 * ======================== Circle implementation ========================
 */

void Circle::move() { this->position = this->position + this->velocity; }

/*
 * ======================== Function implementations ========================
 */

float geom::distance(const Point2 &firstPoint, const Point2 &secondPoint) {
  float dx = firstPoint.x - secondPoint.x;
  float dy = firstPoint.y - secondPoint.y;

  return (dx * dx + dy * dy);
}

bool geom::hasCollision(const Circle &firstCircle, const Circle &secondCircle) {
  float radiiSum = firstCircle.radius + secondCircle.radius;
  float centersDistance =
      geom::distance(firstCircle.position, secondCircle.position);

  return centersDistance <= radiiSum;
}

void geom::displace(Circle &firstCircle, Circle &secondCircle);

void geom::solveCollision(Circle &firstCircle, Circle &secondCircle);

float geom::qOverlap(const Circle &firstCircle, const Circle &secondCircle) {
  float radiiSum = firstCircle.radius + secondCircle.radius;
  return radiiSum - geom::distance(firstCircle.position, secondCircle.position);
}

float geom::dot(const Vec2 &firstVec, const Vec2 &secondVec) {
  return firstVec.x * secondVec.x + firstVec.y * secondVec.y;
}

Vec2 geom::projection(const Vec2 &firstVec, const Vec2 &secondVec) {
  float mag = secondVec.magnitude();
  return secondVec.scalarProduct(geom::dot(firstVec, secondVec) / (mag * mag));
}
