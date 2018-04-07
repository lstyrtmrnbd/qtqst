#include "pathgraph.hpp"

PathGraph::PathGraph() {

  edges = new std::unordered_map<PathNode, std::vector<PathNode*>>();  
}

PathGraph::~PathGraph() {

  delete edges;
}

const std::vector<PathNode*>& PathGraph::getNeighbors(const PathNode& node) {

  return edges[node];
}

void PathGraph::pushNeighbor(const PathNode& node, PathNode* neighbor) {

  edges[node].push_back(neighbor);
}
