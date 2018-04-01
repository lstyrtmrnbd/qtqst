#ifndef LEVEL_PAINTER_INCLUDE
#define LEVEL_PAINTER_INCLUDE

#include <iostream>

#include "level.hpp"
#include "existentenvironments.hpp"
#include "region.hpp"
#include "regionpainter.hpp"
#include "cell.hpp"
#include "terrain.hpp"

/**
 * -This is a singleton because it needs to know the ExistentEnvironments
 */
class LevelPainter {

public:

  LevelPainter(ExistentEnvironments*); 
  
  Level* paintEmptyLevel(int width, int height);

private:

  ExistentEnvironments* environments;

};

#endif // LEVEL_PAINTER_INCLUDE
