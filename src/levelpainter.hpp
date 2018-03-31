#ifndef LEVEL_PAINTER_INCLUDE
#define LEVEL_PAINTER_INCLUDE

#include "level.hpp"
#include "region.hpp"
#include "regionpainter.hpp"
#include "cell.hpp"
#include "terrain.hpp"

class LevelPainter {

public:

  static Level* paintEmptyLevel(int width, int height);

};

#endif // LEVEL_PAINTER_INCLUDE
