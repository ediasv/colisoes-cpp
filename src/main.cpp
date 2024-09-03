#include "../include/Ball.hpp"
#include "../include/Constants.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

#define N_BALLS 5
#define RESTITUTION_COEF 1

int main() {

  sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong",
                          sf::Style::Close | sf::Style::Titlebar);

  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window

  std::vector<Ball> balls;

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
