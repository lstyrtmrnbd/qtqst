#ifndef PATHGRAPH_INCLUDE
#define PATHGRAPH_INCLUDE

#include <map>
#include <vector>

#include "pathnode.hpp"

class PathGraph {

public:

  PathGraph();
  ~PathGraph();

  const std::vector<PathNode*>& getNeighbors(const PathNode&);
  void pushNeighbor(const PathNode&, PathNode*);

private:

  std::unordered_map<PathNode, std::vector<PathNode*>>* edges;
  
};

#endif
