#ifndef PATHGRAPH_INCLUDE
#define PATHGRAPH_INCLUDE

#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

#include "pathnode.hpp"

// function object to hash a node, just XOR's the hash of x and y members
struct hashNode {

  std::size_t operator()(const PathNode& node) const {

    return std::hash<int>()(node.x) ^ std::hash<int>()(node.y);
  }
};

// this mapping is the graph
using Pathmap = std::vector<std::vector<std::pair<PathNode, std::vector<PathNode*>>>>;

using NodeGrid = std::vector<std::vector<PathNode>>;

using NeighborGrid = std::vector<std::vector<std::vector<PathNode*>>>;

class PathGraph {

public:
  
  PathGraph();
  ~PathGraph();

  const std::vector<PathNode*>& getNeighbors(PathNode);
  void pushNeighbor(PathNode, PathNode)
  void pushNeighbor(PathNode, PathNode*);
  int getSize();

  friend std::ostream& operator<<(std::ostream&, const PathGraph&);

private:

  Pathmap* edges;

};

#endif
