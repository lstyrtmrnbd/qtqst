#ifndef PATHNODE_INCLUDE
#define PATHNODE_INCLUDE

#include "cell.hpp"

class PathNode {

public:

  PathNode(Cell&); // construct me by grabbing cell terrain difficulty

  bool passable = true;  // deduced from Cell entity stack on construction
  int difficulty = 0;    // additional cost to cross

  // just compares difficulty, needed so pathnode can be a map key
  bool operator<(const PathNode& rhs) const;
  
};

#endif // PATHNODE_INCLUDE
