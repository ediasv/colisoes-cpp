#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>

#define WIN_HEIGHT 700
#define WIN_WIDTH 1200

int main() {

  sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong",
                          sf::Style::Close | sf::Style::Titlebar);

  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window

  sf::RectangleShape bola(sf::Vector2(50.f, 50.f));
  bola.setPosition(WIN_WIDTH / 2.f, WIN_HEIGHT / 2.f);

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) { // while there are pending events...

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // clears the window
    window.clear(sf::Color::Black);

    window.draw(bola);

    // renders the display buffer
    window.display();
  }
  return 0;
}
