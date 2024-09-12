#include "../include/Geometry.hpp"
#include <iostream>

int main() {
  geom::Vec2 a(123, 0);
  geom::Vec2 b(2, 2);
  geom::Vec2 c = geom::projection(b, b);
  std::cout << c.x << " " << c.y << std::endl;
  return 0;
}
