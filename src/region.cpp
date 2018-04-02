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

  std::cout << "Values used by iteration: top: " << top << " left: " << left
            << " bot: " << bottom << " right: " << right << "\n";

  std::vector<std::vector<Cell>>::iterator yStart = cells->begin() + top; // dereference to get a vector<Cell> row
  std::vector<Cell>::iterator xStart = yStart->begin() + left;                 // dereference to get a Cell

  std::vector<std::vector<Cell>>::iterator yLimit = cells->begin() + bottom;
  std::vector<Cell>::iterator xLimit = yLimit->begin() + right;

  std::cout << "Iterators initialized" << "\n";
  
  for(auto y = yStart; y != yLimit; ++y) {

    int yCount = std::distance(cells->begin(), y);
    //std::cout << "Exterior iteration: " << yCount << "\n";

    for(auto x = xStart; x != xLimit; ++x) {

      int xCount = std::distance(y->begin(), x);
      //std::cout << "Interior iteration: " << xCount << "\n";

      x->announceSelf();

      //std::cout << "cells exists" << "\n";
      
      //Cell& tmpCell = cells->at(yCount).at(xCount);

      Terrain::TerrainType cellType = x->getTerrainType();

      //std::cout << "Not segfaulting on 'x' dereference" << "\n";

      //swift::Sprite temp(*batch, environment->getSpriteBox(cellType));
      
      //set sprite position!!
      
      //staticSprites->push_back(temp);
    }
  }
}

void Region::render(double dtime, sf::RenderWindow& window) {

  window.draw(*batch);
}
