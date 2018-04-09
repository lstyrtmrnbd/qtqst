#ifndef PATHGRAPH_INCLUDE
#define PATHGRAPH_INCLUDE

#include <functional>
#include <unordered_map>
#include <vector>

#include "pathnode.hpp"

// function object to hash a node, just OR's the hash of x and y members
struct hashNode {

  std::size_t operator()(const PathNode& node) const {

    return std::hash<int>()(node.x) ^ std::hash<int>()(node.y);
  }
};

// this mapping is the graph
using Pathmap = std::unordered_map<PathNode, std::vector<PathNode>, hashNode>;

class PathGraph {

public:
  
  PathGraph();
  ~PathGraph();

  const std::vector<PathNode>& getNeighbors(PathNode);
  void pushNeighbor(PathNode, PathNode);

  friend std::ostream& operator<<(std::ostream&, const PathGraph&);

private:

  Pathmap* edges;

  
  
};

#endif
