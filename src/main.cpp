#include "../include/ball.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <vector>

#define N_BALLS 0
#define RESTITUTION_COEF 1
#define RADIUS 20.f

int main() {
  srand(time(0));

  sf::RenderWindow window(sf::VideoMode(width, heigth), "Pong",
                          sf::Style::Close | sf::Style::Titlebar);

  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window

  std::vector<Ball> balls;
  int i, j;
  for (int i = 0; i < N_BALLS; i++) {
    balls.push_back(Ball());
  }
  // for (i = 0; i < N_BALLS; i++) {
  //   for (j = i + 1; j < N_BALLS; j++) {
  //     if (hasOverlap(balls, i, j)) {
  //       balls.at(j) = balls.back();
  //       balls.pop_back();
  //     }
  //   }
  // }
  Ball a;

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) { // while there are pending events...

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // clears the window
    window.clear(sf::Color::Black);

    window.draw(a.shape);

    for (i = 0; i < N_BALLS; i++) {
      window.draw(balls.at(i).shape);
      balls.at(i).move();
    }

    // renders the display buffer
    window.display();
  }

  return 0;
}
