#include "region.hpp"

Region::Region(int left, int top, int right, int bottom,
               std::vector<std::vector<Cell>>* cells):
  left(left), top(top), right(right), bottom(bottom), cells(cells) {

  environment = NULL;
  
  width = right - left;
  height = bottom - top;

  staticSprites = std::vector<swift::Sprite*>();
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

swift::SpriteBatch& Region::getBatch() {

  return (*batch);
}

swift::Sprite& Region::getStaticSprite(unsigned int index) {

  if(index < 0 || index > staticSprites.size()) {

    std::cout << "Region::getStaticSprite index out of bounds, returned first" << "\n";
    return *staticSprites.front();
  } else return *staticSprites.at(index);
}

int Region::getSize() {

  return width * height;
}

int Region::getLeft() {

  return left;
}

int Region::getTop() {

  return top;
}

int Region::getRight() {

  return right;
}

int Region::getBottom() {

  return bottom;
}

std::vector<std::vector<Cell>>* Region::getLevelCells() {

  return cells;
}

void Region::buildBatch() {

  if(environment == NULL) {

    std::cout << "Environment must be initialized before buildBatch" << "\n";
    return;
  }

  std::cout << *environment; // DBG

  sf::Texture& ss = *(environment->getSpritesheet());
  
  batch = new swift::SpriteBatch(ss, width * height);

  for(auto y = (cells->begin() + top); y < (cells->begin() + bottom); ++y) {

    int yCount = std::distance(cells->begin(), y);
    
    for(auto x = (y->begin() + left); x < (y->begin() + right); ++x) {

      int xCount = std::distance(y->begin(), x);

      Terrain::TerrainType cellType = x->getTerrainType();

      swift::Sprite* temp = new swift::Sprite(*batch, environment->getSpriteBox(cellType));

      sf::FloatRect localCoords = temp->getLocalBounds();
      float xPos = xCount * localCoords.width;
      float yPos = yCount * localCoords.height;

      temp->setPosition({xPos,yPos});

      //std::cout << "Sprite at pos " << xPos << ", " << yPos << "\n"; // DBG
      
      staticSprites.push_back(temp); //SUSPECT
    }
  }

  std::cout << "staticSprites holds " << staticSprites.size() << " sprites\n";

  std::cout << "Region has a " << *batch;
}

void Region::render(double dtime, sf::RenderWindow &window) {

  //std::cout << "Drawing: " << *batch;
  window.draw(*batch);
}

void Region::doRegionCells(std::function<void(Cell, int, int)> fx) {

  for(auto y = cells->begin() + top; y < cells->begin() + bottom; ++y) {

    int cellY = std::distance(cells->begin(), y);

    for(auto x = y->begin() + left; x < y->begin() + right; ++x) {

      int cellX = std::distance(y->begin(), x);

      fx(*x, cellX, cellY);
    }
  }
}
