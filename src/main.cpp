#include "../include/Constants.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

#define N_BALLS 1
#define BALL_RADIUS 20.f

int main() {

  sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong",
                          sf::Style::Close | sf::Style::Titlebar);

  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window

  std::vector<sf::CircleShape> balls;
  // loop pra criar vetor de bolas;
  for (int i = 0; i < N_BALLS; i++) {
    sf::CircleShape ball;
    ball.setRadius(BALL_RADIUS);
    ball.setPosition(sf::Vector2(0.f, 0.f));
    ball.setFillColor(sf::Color::White);
    balls.push_back(ball);
  }

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) { // while there are pending events...

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // clears the window
    window.clear(sf::Color::Black);

    for (sf::CircleShape ball : balls) {
      window.draw(ball);
    }

    // renders the display buffer
    window.display();
  }

  return 0;
}
