#include "pathgraph.hpp"

PathGraph::PathGraph() {

  edges = new Pathmap();  
}

PathGraph::~PathGraph() {

  delete edges;
}

const std::vector<PathNode*>& PathGraph::getNeighbors(PathNode node) {

  return (*edges)[node];
}

void PathGraph::pushNeighbor(PathNode node, PathNode neighbor) {

  (*edges)[node].push_back(&neighbor);
}

void PathGraph::pushNeighbor(PathNode node, PathNode* neighbor) {

  (*edges)[node].push_back(neighbor);
}

int PathGraph::getSize() {

  return edges->size();
}

std::ostream& operator<<(std::ostream& out, const PathGraph& graph) {

  return out << "PathGraph of map size: " << graph.edges->size() << "\n";
}
