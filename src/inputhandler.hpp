#ifndef INPUT_HANDLER_INCLUDE
#define INPUT_HANDLER_INCLUDE

#include <string>
#include <map>

#include <SFML/Graphics.hpp>

class InputHandler {

public:

  enum InputState {

    playerMove,
    optionsMenu
  };

  InputHandler(sf::RenderWindow& window, sf::CircleShape& player);
  ~InputHandler();
  void changeInputState(InputState newState);
  void handleInput(sf::Event& event);

private:

  sf::RenderWindow& window;
  sf::CircleShape& player;
  InputState state;
  std::map<std::string, sf::Keyboard::Key>* keyMap;

  void handlePlayerInput(sf::Event& event);
};

#endif // INPUT_HANDLER_INCLUDE
