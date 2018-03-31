#include "level.hpp"

Level::Level(int width, int height): width(width), height(height) {

  cells = new std::vector<std::vector<Cell>>(width, std::vector<Cell>(height));
  entities = new std::vector<Entity>();
}

//this assumes the cell grid passed in is prefilled, and really it should be
Level::Level(std::vector<std::vector<Cell>>* cells): cells(cells) {

  width = cells->size();
  height = (*cells)[0].size(); // real elegant, lmfao
}

Level::~Level() {

  delete cells;
  delete entities;
}
