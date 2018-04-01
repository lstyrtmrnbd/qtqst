#include "region.hpp"

Region::Region(int left, int top, int right, int bottom, std::vector<std::vector<Cell>>*):
  left(left), top(top), right(right), bottom(bottom), cells(cells) {

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

void Region::setEnvironment(Environment* environment) {

  this->environment = environment;
}

void Region::buildBatch() {

  if(environment == NULL) {

    std::cout << "Environment must be initialized before buildBatch" << "\n";
    return;
  }

  sf::Texture& ss = *(environment->getSpritesheet());

  std::cout << "A convenience reference?" << "\n";
  
  batch = new swift::SpriteBatch(ss, 2);

  std::cout << "The Region's batch is made" << "\n";

  staticSprites = new std::vector<swift::Sprite>();

  std::cout << "The staticSprite vector is initialized" << "\n";
  
  std::vector<std::vector<Cell>>::iterator y; // dereference to get a vector<Cell> row
  std::vector<Cell>::iterator x;              // dereference to get a Cell

  std::vector<std::vector<Cell>>::iterator yLimit = cells->begin() + bottom;
  std::vector<Cell>::iterator xLimit = yLimit->begin() + right;
  
  for(y = (cells->begin() + top); y <= yLimit - 1; y++) {

    for(x = (y->begin() + left); x <= xLimit - 1; x++) {

      swift::Sprite temp(*batch, environment->getSpriteBox( x->getTerrainType() ));
      //set sprite position
      
      staticSprites->push_back(temp);
    }
  }
}

void Region::render(double dtime, sf::RenderWindow& window) {

  window.draw(*batch);
}
