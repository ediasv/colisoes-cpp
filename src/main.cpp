#include "../include/Ball.hpp"
#include <SFML/Graphics.hpp>

int main() {
  srand(time(0));

  sf::RenderWindow window(sf::VideoMode(width, height), "Particles",
                          sf::Style::Close | sf::Style::Titlebar);
  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window
  window.requestFocus();

  BallVector ballPoll = BallVector();
  int i, j;

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) { // while there are pending events...

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // clears the window
    window.clear(sf::Color::Black);

    for (Ball &ball : ballPoll.balls) {
      window.draw(ball.draw());

      for (Ball &target : ballPoll.balls) {
        if (&ball == &target) {
          continue;
        }

        if (hasOverlap(ball, target)) {
          displace(ball, target);
        }
      }

      ball.move();
    }

    // renders the display buffer
    window.display();
  }

  return 0;
}
