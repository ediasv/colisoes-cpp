#include "../include/Engine.hpp"
#include "../include/Geometry.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

const short int width = 900;
const short int height = 1200;
const int n_balls = 100;

int main() {
  srand(time(0));

  sf::RenderWindow window(sf::VideoMode(width, height), "Particles",
                          sf::Style::Close | sf::Style::Titlebar);
  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window
  window.requestFocus();

  geom::Circles circles(n_balls);
  my::Shapes<sf::CircleShape> shapeContainer(n_balls);

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) { // while there are pending events...

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // clears the window
    window.clear(sf::Color::Black);

    for (geom::Circle &circle : CircleContainer) {
      window.draw();

      for (Ball &target : ballPoll.balls) {
        if (&ball == &target) {
          continue;
        }

        if (hasOverlap(ball, target)) {
          colide(ball, target);
        }
      }

      ball.move();
    }

    // renders the display buffer
    window.display();
  }

  return 0;
}
