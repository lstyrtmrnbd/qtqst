#include "levelpainter.hpp"

LevelPainter::LevelPainter(ExistentEnvironments* environments): environments(environments) {
  
}

Level* LevelPainter::paintEmptyLevel(int width, int height) {
  
  Terrain terrain(Terrain::TerrainType::grass); // grass is the "default" terrain
  
  std::vector<std::vector<Cell>>* pCells = new std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Cell(terrain)));

  Cell derefTest = (*pCells)[0][0];
  derefTest.announceSelf();

  derefTest = (*pCells)[16][16];
  derefTest.announceSelf();

  std::cout << "The grid was initialized" << "\n";

  std::vector<Region>* regions = new std::vector<Region>(1, Region(0, 0, width, height, pCells));

  std::cout << "The Region was constructed" << "\n";

  regions->front().setEnvironment(environments->defaultEnvironment);

  std::cout << "The environment was set" << "\n";

  RegionPainter::paintEmptyRegion(regions->front());

  std::cout << "The Region was painted" << "\n";
  
  Level* newLevel = new Level(pCells, regions);
}
