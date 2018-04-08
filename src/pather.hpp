#ifndef PATHER_INCLUDE
#define PATHER_INCLUDE

#include <queue>

#include "pathgraph.hpp"
#include "pathnode.hpp"
#include "region.hpp"

using Pathmap = std::map<PathNode, PathNode>;

class Pather {

 public:

  static PathGraph* parseRegion(Region&);
  static Pathmap* breadthFirst(PathGraph&);
  
 private:

  std::priority_queue<PathNode> pq;
};

#endif // PATHER_INCLUDE
