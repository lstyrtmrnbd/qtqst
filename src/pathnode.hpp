#ifndef PATHNODE_INCLUDE
#define PATHNODE_INCLUDE

#include <functional>

#include "cell.hpp"

class PathNode {

public:

  PathNode(Cell&, int x, int y); // construct me by grabbing cell info

  int x, y;
  bool passable = true;  // deduced from Cell entity stack on construction
  int difficulty = 0;    // additional cost to cross
 
  // these operators allow use of pathnode as map keys
  bool operator<(const PathNode& rhs) const;  // for std::map
  bool operator==(const PathNode& rhs) const; // for std::unordered_map
};

#endif // PATHNODE_INCLUDE
