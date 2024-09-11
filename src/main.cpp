#include "../include/Ball.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

int main() {

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

    for (i = 0; i < ballPoll.n_balls; i++) {
      window.draw(ballPoll.balls.at(i).draw());
      ballPoll.balls.at(i).move();
      for (j = i + 1; j < ballPoll.n_balls; j++) {
        if (hasOverlap(ballPoll.balls, i, j)) {
          colide(ballPoll.balls.at(i), ballPoll.balls.at(j));
        }
      }
    }

    // renders the display buffer
    window.display();
  }

  return 0;
}
