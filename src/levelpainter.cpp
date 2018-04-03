#include "levelpainter.hpp"

LevelPainter::LevelPainter(ExistentEnvironments *environments): environments(environments) {
  
}

Level* LevelPainter::paintEmptyLevel(int width, int height) {
  
  Terrain terrain(Terrain::TerrainType::grass); // grass is the "default" terrain
  
  std::vector<std::vector<Cell>>* pCells = new std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Cell(terrain)));
  
  std::vector<Region>* regions = new std::vector<Region>(1, Region(0, 0, width, height, pCells));

  regions->front().setEnvironment(environments->defaultEnvironment);

  std::cout << regions->front(); // DBG

  RegionPainter::paintEmptyRegion(regions->front());

  std::cout << "The Region was painted" << "\n";
  
  return new Level(pCells, regions);
}
