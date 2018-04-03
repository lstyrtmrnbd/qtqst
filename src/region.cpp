#include "region.hpp"

Region::Region(int left, int top, int right, int bottom,
               std::vector<std::vector<Cell>>* cells):
  left(left), top(top), right(right), bottom(bottom), cells(cells) {

  environment = NULL;
  
  width = right - left;
  height = bottom - top;
}

Region::~Region() {

  //delete batch; // ??
}

std::ostream& operator<<(std::ostream &out, const Region &region) {

  std::string envValid = (region.environment != NULL ? "valid" : "invalid");
  std::string cellsValid = (region.cells != NULL ? "valid" : "invalid");

  return out << "Region at (" << region.left << ", " << region.top
             << ") of size (" << region.width << ", " << region.height << ")\n"
             << " -environment pointer is " << envValid << "\n"
             << " -pointer to parent level cells is " << cellsValid << "\n"; 
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

  std::cout << *environment; // DBG

  sf::Texture& ss = *(environment->getSpritesheet());
  
  batch = new swift::SpriteBatch(ss, width * height);

  staticSprites = new std::vector<swift::Sprite>(width * height);

  std::vector<std::vector<Cell>>::iterator yStart = cells->begin() + top; // dereference to get a vector<Cell> row
  std::vector<Cell>::iterator xStart = yStart->begin() + left;            // dereference to get a Cell

  std::vector<std::vector<Cell>>::iterator yLimit = cells->begin() + bottom;
  std::vector<Cell>::iterator xLimit = yLimit->begin() + right;

  std::cout << "Values used by iteration:"
            << "\n yStart: " << std::distance(cells->begin(), yStart)
            << "\n xStart: " << std::distance(yStart->begin(), xStart)
            << "\n yLimit: " << std::distance(cells->begin(), yLimit)
            << "\n xLimit: " << std::distance(yLimit->begin(), xLimit) << "\n"; // DBG
  
  for(auto y = yStart; y <= yLimit; ++y) {

    int yCount = std::distance(cells->begin(), y);
    //std::cout << "Exterior iteration: " << yCount << "\n";

    for(auto x = xStart; x <= xLimit; ++x) {

      int xCount = std::distance(y->begin(), x);

      Terrain::TerrainType cellType = x->getTerrainType();

      swift::Sprite temp(*batch, environment->getSpriteBox(cellType));

      sf::FloatRect localCoords = temp.getLocalBounds();
      float xPos = xCount * localCoords.width;
      float yPos = yCount * localCoords.height;

      temp.setPosition({xPos,yPos});

      std::cout << "Sprite at pos " << xPos << ", " << yPos << "\n"; // DBG
      
      staticSprites->push_back(temp);
    }
  }
}

void Region::render(double dtime, sf::RenderWindow &window) {

  window.draw(*batch);
}
