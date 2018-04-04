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

swift::SpriteBatch& Region::getBatch() {

  return (*batch);
}

swift::Sprite& Region::getStaticSprite(unsigned int index) {

  if(index < 0 || index > staticSprites->size()) {

    std::cout << "Region::getStaticSprite index out of bounds, returned first" << "\n";
    return staticSprites->front();
  } else return staticSprites->at(index);
}

void Region::buildBatch() {

  if(environment == NULL) {

    std::cout << "Environment must be initialized before buildBatch" << "\n";
    return;
  }

  std::cout << *environment; // DBG

  sf::Texture& ss = *(environment->getSpritesheet());
  
  batch = new swift::SpriteBatch(ss, width * height);

  staticSprites = new std::vector<swift::Sprite>();

  for(auto y = (cells->begin() + top); y < (cells->begin() + bottom); ++y) {

    int yCount = std::distance(cells->begin(), y);
    //std::cout << "Exterior iteration: " << yCount << "\n";

    for(auto x = (y->begin() + left); x < (y->begin() + right); ++x) {

      int xCount = std::distance(y->begin(), x);

      Terrain::TerrainType cellType = x->getTerrainType();

      swift::Sprite* temp = new swift::Sprite(*batch, environment->getSpriteBox(cellType));

      sf::FloatRect localCoords = temp->getLocalBounds();
      float xPos = xCount * localCoords.width;
      float yPos = yCount * localCoords.height;

      temp->setPosition({xPos,yPos});

      //std::cout << "Sprite at pos " << xPos << ", " << yPos << "\n"; // DBG
      
      staticSprites->push_back(*temp);
    }
  }

  std::cout << "staticSprites holds " << staticSprites->size() << " sprites\n";

  std::cout << "Region has a " << *batch;
}

void Region::render(double dtime, sf::RenderWindow &window) {

  //std::cout << "Drawing: " << *batch;
  window.draw(*batch);
}
