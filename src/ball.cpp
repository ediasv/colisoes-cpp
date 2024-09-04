#include "../include/ball.hpp"
#include <SFML/Graphics/Color.hpp>
#include <cstdlib>
#include <ctime>

Ball::Ball() {
  srand(time(0));
  m_vx = rand() % 16;
  m_vy = rand() % 16;
  // m_x = (rand() % (width - (int)radius + 1)) + radius;
  // m_y = (rand() % (heigth - (int)radius + 1)) + radius;
  m_x = 0;
  m_y = 0;
  shape.setRadius(radius);
  shape.setPosition(m_x, m_y);
  shape.setFillColor(sf::Color::White);
}

void Ball::move() {
  m_x += m_vx;
  m_y += m_vy;

  // check wall collision
  if (m_x - radius <= 0) {
    m_x = 0;
    m_vx *= -1;
  } else if (m_x + radius >= width) {
    m_x = width - radius;
    m_vx *= -1;
  }

  if (m_y - radius <= 0) {
    m_y = 0;
    m_vy *= -1;
  } else if (m_y + radius >= heigth) {
    m_y = heigth - radius;
    m_vy *= -1;
  }

  shape.setPosition(m_x, m_y);
}
