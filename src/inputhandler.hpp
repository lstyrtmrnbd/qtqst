#ifndef INPUT_HANDLER_INCLUDE
#define INPUT_HANDLER_INCLUDE

#include <SFML/Graphics.hpp>

class InputHandler {

public:

  enum InputState {

    gameplay
  };

  InputHandler(sf::RenderWindow& window, sf::CircleShape& player);
  void changeState(InputState newState);
  void handleInput(sf::Event& event);

private:

  sf::RenderWindow& window;
  sf::CircleShape& player;
  InputState state;
};

#endif // INPUT_HANDLER_INCLUDE
