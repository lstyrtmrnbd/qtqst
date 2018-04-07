#include "pathnode.hpp"

// does not currently deduce passability
PathNode::PathNode(Cell& cell) {

  this->difficulty = cell.getDifficulty();
}

bool PathNode::operator<(const PathNode& rhs) const {

  return this->difficulty < rhs.difficulty;
}
