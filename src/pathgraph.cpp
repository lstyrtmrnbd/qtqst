#include "pathgraph.hpp"

PathGraph::PathGraph() {

  edges = std::map<PathNode, std::vector<PathNode*>>();  
}

const std::vector<PathNode*>& PathGraph::getNeighbors(const PathNode& node) {

  return edges[node];
}

void PathGraph::pushNeighbor(const PathNode& node, PathNode* neighbor) {

  edges[node].push_back(neighbor);
}
