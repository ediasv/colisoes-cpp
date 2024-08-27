/*#include "../include/sayhello.hpp"*/
#include <SFML/Graphics.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

using namespace std;

int main() {
  sf::Window window(sf::VideoMode(800, 600), "My window");
  window.setVerticalSyncEnabled(true); // VSYNC
  window.setFramerateLimit(30); // call it once, after creating the window

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) { // while there are pending events...
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::MouseMoved) {
        cout << event.mouseMove.x << " " << event.mouseMove.y << endl;
      }
    }
  }

  return 0;
}
