#ifndef PATHER_INCLUDE
#define PATHER_INCLUDE

#include <queue>

#include "pathgraph.hpp"
#include "pathnode.hpp"
#include "region.hpp"

using Previousmap = std::map<PathNode, PathNode>;

class Pather {

 public:

  static PathGraph* parseRegion(Region&);
  static Previousmap* breadthFirst(PathGraph&, int, int);
  
 private:

  std::priority_queue<PathNode> pq;
};

#endif // PATHER_INCLUDE
