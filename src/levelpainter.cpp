#include "levelpainter.hpp"

Level* LevelPainter::paintEmptyLevel(int width, int height) {

  std::vector<std::vector<Cell>>* cells;
  
  Terrain terrain = Terrain(Terrain::TerrainType::grass); // grass is the "default" terrain
  
  cells = new std::vector<std::vector<Cell>>(width, std::vector<Cell>(height, Cell(terrain)));

  std::vector<Region>* regions = new std::vector<Region>(1, Region(0, 0, width, height));

  RegionPainter::paintEmptyRegion(regions->front());
  
  Level* newLevel = new Level(cells, regions);
}
