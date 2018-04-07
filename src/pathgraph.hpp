#ifndef PATHGRAPH_INCLUDE
#define PATHGRAPH_INCLUDE

#include <map>
#include <vector>

#include "pathnode.hpp"

class PathGraph {

public:

  PathGraph();

  const std::vector<PathNode*>& getNeighbors(const PathNode&);
  void pushNeighbor(const PathNode&, PathNode*);

private:

  std::map<PathNode, std::vector<PathNode*>> edges;
  
};

#endif
