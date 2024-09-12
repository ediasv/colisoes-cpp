#pragma once

#include "Geometry.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

namespace my {

// Struct used to render circles created with geom::Circle()
struct CircleRenderer {
  sf::CircleShape shape;

  CircleRenderer(const geom::Circle &circle);

  void updatePosition(const geom::Circle &circle);
  sf::CircleShape getShape() const;
};

// Container for Geometry.hpp shapes
template <typename ShapeType> struct Shapes {
  std::vector<ShapeType> shapes;

  Shapes(int n_shapes);

  void addShape(const ShapeType &shape);
};

} // namespace my
