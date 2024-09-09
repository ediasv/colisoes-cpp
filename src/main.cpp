#include "../include/ball.hpp"
#include <SFML/Graphics.hpp>

int main() {

  sf::RenderWindow window(sf::VideoMode(width, heigth), "Particles",
                          sf::Style::Close | sf::Style::Titlebar);
  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window
  window.requestFocus();

  BallVector balls = BallVector();

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) { // while there are pending events...

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // clears the window
    window.clear(sf::Color::Black);

    for (int i = 0; i < balls.n_balls; i++) {
      window.draw(balls.balls.at(i).draw());
      balls.balls.at(i).move();
    }

    // renders the display buffer
    window.display();
  }

  return 0;
}
