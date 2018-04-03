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
