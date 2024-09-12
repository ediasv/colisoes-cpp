#pragma once

#include "Geometry.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

namespace my {

struct CircleRenderer {
  sf::CircleShape shape;

  CircleRenderer(const geom::Circle &circle);

  void updatePosition(const geom::Circle &circle);
  sf::CircleShape getShape() const;
};

template <typename ShapeType> struct Shapes {
  std::vector<ShapeType> shapes;

  Shapes(int n_shapes);

  void addShape(const ShapeType &shape);
};

} // namespace my
