#include "inputhandler.hpp"

InputHandler::InputHandler(sf::RenderWindow& window, sf::CircleShape& player):
  window(window), player(player) {

  this->state = playerMove;
  
  keyMap = new std::map<std::string, sf::Keyboard::Key>();

  (*keyMap)["left"] = sf::Keyboard::Left;
  (*keyMap)["right"] = sf::Keyboard::Right;
  (*keyMap)["up"] = sf::Keyboard::Up;
  (*keyMap)["down"] = sf::Keyboard::Down;
  (*keyMap)["quit"] = sf::Keyboard::Escape;
  
}

void InputHandler::changeInputState(InputState newState) {

  this->state = newState;
}

void InputHandler::handlePlayerInput(sf::Event& event) {

  std::map<std::string, sf::Keyboard::Key>& keys = *this->keyMap;

  if(event.type == sf::Event::KeyPressed) {

    sf::Keyboard::Key key = event.key.code;

    if(key == keys["left"]) {
      
        player.setFillColor(sf::Color::Red);
        
    } else if(key == keys["right"]) {

        player.setFillColor(sf::Color::Green);
        
    } else if(key == keys["up"]) {

        player.setFillColor(sf::Color::Blue);
        
    } else if(key == keys["down"]) {
              
        player.setFillColor(sf::Color::Yellow);
        
    } else if(key == keys["quit"]) {

        window.close();
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
