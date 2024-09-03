#include "../include/Ball.hpp"
#include "../include/Constants.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>

#define N_BALLS 1

float randFloat(int min, int max);

int main() {

  sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong",
                          sf::Style::Close | sf::Style::Titlebar);

  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window

  std::vector<Ball> balls;
  int i;
  for (i = 0; i < N_BALLS; i++) {
    balls.push_back(Ball());
  }

  int a;

  sf::CircleShape ball;
  ball.setRadius(randFloat(5, 50));
  ball.setPosition(randFloat(0, 10), randFloat(0, 10));
  ball.setFillColor(sf::Color::White);

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) { // while there are pending events...

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // clears the window
    window.clear(sf::Color::Black);

    window.draw(ball);
    ball.setPosition(ball.getPosition().x + 5, ball.getPosition().y);

    // renders the display buffer
    window.display();
  }

  return 0;
}

float randFloat(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  return (float)distr(gen);
}
