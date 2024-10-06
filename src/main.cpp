#include "../include/Engine.hpp"
#include "../include/Geometry.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

const int width = 1200;
const int height = 900;
const int n_particles = 20;

int main() {
  srand(time(0));

  sf::RenderWindow window(sf::VideoMode(width, height), "Particles",
                          sf::Style::Close | sf::Style::Titlebar);
  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window
  window.requestFocus();

  my::Shapes<geom::Circle> particles(n_particles);

  std::vector<my::CircleRenderer> particlesRenderer;

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) { // while there are pending events...

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // clears the window
    window.clear(sf::Color::Black);

    // renders the display buffer
    window.display();
  }

  return 0;
}
