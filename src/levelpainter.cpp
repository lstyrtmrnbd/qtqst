#include "levelpainter.hpp"

Level* LevelPainter::paintEmptyLevel(int width, int height) {

  std::vector<std::vector<Cell>>* cells;
  cells = new std::vector<std::vector<Cell>>(width, std::vector<Cell>(height, Cell(Terrain(TerrainType::grass))));

  std::vector<Region>* regions = new std::vector<Region>(1, Region(0, 0, width, height));

  RegionPainter::paintEmptyRegion(regions.front());
  
  Level* newLevel = new Level();
}
