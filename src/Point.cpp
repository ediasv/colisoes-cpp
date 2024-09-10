#include "../include/Point.hpp"

Point::Point() : x(0.f), y(0.f) {}

Point::Point(int x, int y) : x((float)x), y((float)y) {}

Point::Point(float x, float y) : x(x), y(y) {}
