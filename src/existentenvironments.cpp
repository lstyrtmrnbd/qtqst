#include "existentenvironments.hpp"

ExistentEnvironments::ExistentEnvironments(sf::Texture* defaultTexture): defaultTexture(defaultTexture) {

  defaultEnvironment = new Environment(defaultTexture);
  
  defaultEnvironment->setSpriteBox(Terrain::TerrainType::grass,
                                   sf::IntRect(96, 1376, 96 + 32, 1376 + 32));

}
