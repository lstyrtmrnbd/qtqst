#ifndef PATHER_INCLUDE
#define PATHER_INCLUDE

#include <queue>

#include "pathgraph.hpp"
#include "pathnode.hpp"
#include "region.hpp"

class Pather {

 public:

  static PathGraph* parseRegion(Region&);
  
 private:

  std::priority_queue<PathNode> pq;
};

#endif // PATHER_INCLUDE
