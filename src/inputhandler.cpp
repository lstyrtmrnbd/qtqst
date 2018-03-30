#include "inputhandler.hpp"

InputHandler::InputHandler(sf::RenderWindow& window, sf::CircleShape& player):
  window(window), player(player) {

}

void InputHandler::changeState(InputState newState) {

  this->state = newState;
}

void InputHandler::handleInput(sf::Event& event) {

  if(event.type == sf::Event::Closed) {

    window.close();
  }
  
  if(event.type == sf::Event::KeyPressed) {

    switch(event.key.code) {

      case sf::Keyboard::Left:

        player.setFillColor(sf::Color::Red);
        break;

      case::sf::Keyboard::Right:

        player.setFillColor(sf::Color::Green);
        break;

      case sf::Keyboard::Up:

        player.setFillColor(sf::Color::Blue);
        break;

      case sf::Keyboard::Down:
              
        player.setFillColor(sf::Color::Yellow);
        break;

      case sf::Keyboard::Escape:

        window.close();
        break;

      default:
        break;
    }
  }
}
