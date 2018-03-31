#include "environment.hpp"

Environment::Environment(sf::Texture* spritesheet): spritesheet(spritesheet) {

  terrainSpriteBoxes = new std::map<Terrain::TerrainType, sf::IntRect>();
}

void Environment::setSpriteBox(Terrain::TerrainType terrainType, sf::IntRect spriteBox) {

  (*terrainSpriteBoxes)[terrainType] = spriteBox;
}

sf::IntRect Environment::getSpriteBox(Terrain::TerrainType terrainType) {

  return (*terrainSpriteBoxes)[terrainType];
}

sf::Texture* Environment::getSpritesheet() {

  return spritesheet;
}
