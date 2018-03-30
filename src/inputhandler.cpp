#include "inputhandler.hpp"

InputHandler::InputHandler(sf::RenderWindow& window, sf::CircleShape& player):
  window(window), player(player) {

  keyMap = new std::map<std::string, sf::Keyboard::Key*> {
    std::make_pair( "left", sf::Keyboard::Left ),
    std::make_pair( "right", sf::Keyboard::Right ),
    std::make_pair( "up", sf::Keyboard::Up ),
    std::make_pair( "down", sf::Keyboard::Down)
  };
}

void InputHandler::changeInputState(InputState newState) {

  this->state = newState;
}

void InputHandler::handlePlayerInput(sf::Event& event) {

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

void InputHandler::handleInput(sf::Event& event) {

  if(event.type == sf::Event::Closed) {

    window.close();
  }
  
  switch(this->state) {

    case playerMove:
      handlePlayerInput(event);
      break;

    default:
      break;

  }
}
