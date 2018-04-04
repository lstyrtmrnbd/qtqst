#include "regionpainter.hpp"

void RegionPainter::paintEmptyRegion(Region &region) {

  // modify cell terrain and then build static sprite batch

  // add random dirt patches

  // build static sprites
  region.buildBatch();
}

bool RegionPainter::everyNth(int max, int n) {

  return (randomInt(0, max) < max / n);  
}

int RegionPainter::randomInt(int min, int max) {

  std::default_random_engine engine;
  std::uniform_int_distribution<int> dist(min, max);

  return dist(engine);
}
