#include "level.hpp"

//this assumes the cell grid passed in is prefilled, and really it should be
Level::Level(std::vector<std::vector<Cell>>* cells, std::vector<Region>* regions):
  cells(cells), regions(regions) {

  height = cells->size();
  width = cells->front().size();

  entities = new std::vector<Entity>();
}

Level::~Level() {

  delete cells;
  delete entities;
  delete regions;
}

void Level::render(double dtime, sf::RenderWindow& window) {

  for(auto it = regions->begin(); it != regions->end(); ++it) {

    it->render(dtime, window);
  }
}

Region& Level::getRegion(unsigned int index) {

  if (index < 0 || index > regions->size()) {
    
    std::cout << "Level::getRegion index out of bounds, returned first region" << "\n";
    return regions->front();
  } else return regions->at(index);
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
