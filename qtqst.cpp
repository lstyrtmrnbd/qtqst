#include <SFML/Graphics.hpp>

int main() {
  
  sf::RenderWindow window(sf::VideoMode(640, 480), "qtqst under construction");
  
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
      
    sf::Event event;
        
    while (window.pollEvent(event)) {
          
      switch(event.type) {

        case sf::Event::Closed:

          window.close();
          break;

        case sf::Event::KeyPressed:

          switch(event.key.code) {

            case sf::Keyboard::Left:

              shape.setFillColor(sf::Color::Red);
              break;

            case::sf::Keyboard::Right:

              shape.setFillColor(sf::Color::Green);
              break;

            case sf::Keyboard::Up:

              shape.setFillColor(sf::Color::Blue);
              break;

            case sf::Keyboard::Down:
              
              shape.setFillColor(sf::Color::Yellow);
              break;

            case sf::Keyboard::Escape:

              window.close();
              break;

            default:
              break;
          }
          break;

        default:
          break;
            
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
