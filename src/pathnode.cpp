#include "pathnode.hpp"

// does not currently deduce passability
PathNode::PathNode(Cell& cell, int x, int y): x(x), y(y) {

  this->difficulty = cell.getDifficulty();
}

bool PathNode::operator<(const PathNode& rhs) const {

  return this->difficulty < rhs.difficulty;
}

bool PathNode::operator==(const PathNode& rhs) const {

  return (this->x == rhs.x && this->y == rhs.y);
}
