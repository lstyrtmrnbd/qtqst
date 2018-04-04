#ifndef REGION_PAINTER_INCLUDE
#define REGION_PAINTER_INCLUDE

#include <algorithm>
#include <functional>
#include <random>

#include "region.hpp"

class RegionPainter {

public:

  static void paintEmptyRegion(Region&);

private:

  static void doRegionCells(Region&, std::function<void(Cell)>);
  static int randomInt(int min, int max); // add a seed input if necessary
  static bool everyNth(int max, int div);
  
};

#endif // REGION_PAINTER_INCLUDE
