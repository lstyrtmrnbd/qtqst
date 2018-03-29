#ifndef LEVEL_INCLUDE
#define LEVEL_INCLUDE

#include <vector>

#include "cell.hpp"

class Level {

public:

  Level(int width, int height);
  
private:

  std::vector<vector<Cell>> cells;
 
}

#endif // LEVEL_INCLUDE
