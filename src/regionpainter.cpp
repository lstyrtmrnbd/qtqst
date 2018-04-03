#include "regionpainter.hpp"

void RegionPainter::paintEmptyRegion(Region &region) {

  //modify cell terrain and then build static sprite batch

  region.buildBatch();
}
