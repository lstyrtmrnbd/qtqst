#include "level.hpp"

/** // This is probably pretty useless
Level::Level(int width, int height): width(width), height(height) {

  cells = new std::vector<std::vector<Cell>>(width, std::vector<Cell>(height));
  entities = new std::vector<Entity>();
}
*/

//this assumes the cell grid passed in is prefilled, and really it should be
Level::Level(std::vector<std::vector<Cell>>* cells, std::vector<Region>* regions):
  cells(cells), regions(regions) {

  width = cells->size();
  height = (*cells)[0].size(); // real elegant, lmfao
}

Level::~Level() {

  delete cells;
  delete entities;
}

void Level::render(double dtime, sf::RenderWindow& window) {

  for(auto it = regions->begin(); it != regions->end(); ++it) {

    it->render(dtime, window);
  }
}

std::ostream& operator<<(std::ostream &out, const Level &level) {

  int w;
  int h;
  const char* cellsValid;
  
  if(level.cells != NULL) {

    cellsValid = "valid";
    w = level.cells->front().size();
    h = level.cells->size();
  } else {
    
    cellsValid = "invalid";
    w = 0; h = 0;
  }

  return out << "Level of size (" << w << ", " << h << ")\n"
             << " -contains a " << cellsValid << " cell grid pointer\n"
             << " -subdivided into " << (level.regions != NULL ? level.regions->size() : 0) << " regions\n"
             << " -and " << (level.entities != NULL ? level.entities->size() : 0) << " entities\n";
}
