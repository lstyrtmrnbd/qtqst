#ifndef EXISTENT_ENVIRONMENTS_INCLUDE
#define EXISTENT_ENVIRONMENTS_INCLUDE

#include "environment.hpp"

/**
 * -This is a singleton
 * -It's where the environments exist and are constructed
 * -Textures (the spritesheets) live in a larger scope and are passed in here to be used
 */
class ExistentEnvironments {

public:

  Environment* defaultEnvironment;

  ExistentEnvironments(sf::Texture* defaultTexture); // constructs only the default environment
  
private:

  sf::Texture* defaultTexture;
  
};

#endif // EXISTENT_ENVIRONMENTS_INCLUDE
