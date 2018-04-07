#include "pathgraph.hpp"

PathGraph::PathGraph() {

  edges = new Pathmap();  
}

PathGraph::~PathGraph() {

  delete edges;
}

const std::vector<PathNode>& PathGraph::getNeighbors(PathNode node) {

  return (*edges)[node];
}

void PathGraph::pushNeighbor(PathNode node, PathNode neighbor) {

  (*edges)[node].push_back(neighbor);
}
