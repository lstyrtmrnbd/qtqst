#include "region.hpp"

Region::Region(int left, int top, int right, int bottom): left(left), top(top), right(right), bottom(bottom) {

  environment = NULL;
  width = right - left;
  height = top - bottom;
}

Region::~Region() {

  //delete batch; // ??
}

bool Region::isActive() {

  return activeRegion;
}

void Region::buildBatch() {

  if(environment == NULL) return; //log error too please, this shouldn't happen

  sf::Texture& ss = *(environment->getSpritesheet());
  batch = new swift::SpriteBatch(ss, width * height);

  staticSprites = new std::vector<swift::Sprite>();
  
  std::vector<std::vector<Cell>>::iterator y; // dereference to get a vector<Cell> row
  std::vector<Cell>::iterator x;              // dereference to get a Cell

  std::vector<std::vector<Cell>>::iterator yLimit = cells->begin() + bottom;
  std::vector<Cell>::iterator xLimit = yLimit->begin() + right;
  
  for(y = (cells->begin() + top); y <= yLimit + 1; y++) {

    for(x = (y->begin() + left); x <= xLimit + 1; x++) {

      swift::Sprite temp(*batch, environment->getSpriteBox( x->getTerrainType() ));
      
      staticSprites->push_back(temp);
    }
  }
}
