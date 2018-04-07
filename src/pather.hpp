#ifndef PATHER_INCLUDE
#define PATHER_INCLUDE

#include <queue>

#include "pathgraph.hpp"
#include "pathnode.hpp"
#include "region.hpp"

using Pathlist = std::map<std::pair<int, int>>;

class Pather {

 public:

  static PathGraph* parseRegion(Region&);
  static Pathlist* breadthFirst(PathGraph&);
  
 private:

  std::priority_queue<PathNode> pq;
};

#endif // PATHER_INCLUDE
