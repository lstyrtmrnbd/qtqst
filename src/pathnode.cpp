#include "pathnode.hpp"

// does not currently deduce passability
PathNode::PathNode(Cell& cell, int x, int y): x(x), y(y) {

  this->difficulty = cell.getDifficulty();
}

PathNode::PathNode(int x, int y): x(x), y(y) {

}

bool PathNode::operator<(const PathNode& rhs) const {

  return (this->y < rhs.y) ? true : (this->x < rhs.x);
}

bool PathNode::operator==(const PathNode& rhs) const {

  return (this->x == rhs.x && this->y == rhs.y);
}

bool PathNode::operator!=(const PathNode& rhs) const {

  return !(*this == rhs);
}
