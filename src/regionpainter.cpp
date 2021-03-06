#include "regionpainter.hpp"

void RegionPainter::paintEmptyRegion(Region &region) {

  // modify cell terrain and then build static sprite batch

  // add random dirt patches
  region.doRegionCells([&](Cell &cell, int cellX, int cellY) {

      if(everyNth(4)) {

        cell.setTerrainType(Terrain::TerrainType::dirt);
      } 
    });

  // build static sprites
  std::cout << "Now entering buildBatch\n";
  region.buildBatch();
  std::cout << "Now exiting buildBatch\n";
}

// statistically speaking...
bool RegionPainter::everyNth(int n) {

  return (randomInt(0, n) < 1);  
}

// minor bias towards lower values when range is not a power of 2
int RegionPainter::randomInt(int min, int max) {

  return min + (rand() % static_cast<int>(max - min + 1));
}
