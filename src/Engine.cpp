#include "../include/Engine.hpp"
#include <SFML/Graphics/CircleShape.hpp>

using namespace my;

CircleRenderer::CircleRenderer(const geom::Circle &circle) {
  this->shape.setRadius(circle.radius);
  this->shape.setPosition(circle.position.x, circle.position.y);
}

void CircleRenderer::updatePosition(const geom::Circle &circle) {
  this->shape.setPosition(circle.position.x, circle.position.y);
}

sf::CircleShape CircleRenderer::getShape() const { return this->shape; }

template <typename ShapeType> Shapes<ShapeType>::Shapes(int n_shapes) {
  shapes.reserve(n_shapes);
}

template <typename ShapeType>
void Shapes<ShapeType>::addShape(const ShapeType &shape) {
  shapes.push_back(shape);
}
