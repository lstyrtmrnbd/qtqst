#include "existentenvironments.hpp"

ExistentEnvironments::ExistentEnvironments(sf::Texture* defaultTexture): defaultTexture(defaultTexture) {

  defaultEnvironment = new Environment(defaultTexture);
  
  defaultEnvironment->setSpriteBox(Terrain::TerrainType::grass,
                                   sf::IntRect(96, 1376, 32, 32));

  defaultEnvironment->setSpriteBox(Terrain::TerrainType::dirt,
                                   sf::IntRect(128, 1056, 32, 32));

  defaultEnvironment->setSpriteBox(Terrain::TerrainType::snow,
                                   sf::IntRect(160, 2112, 32, 32));
}
