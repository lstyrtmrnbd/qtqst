#ifndef PATHNODE_INCLUDE
#define PATHNODE_INCLUDE

#include <functional>

#include "cell.hpp"

class PathNode {

public:

  PathNode(Cell&, int x, int y); // construct by grabbing cell info
  PathNode(int x, int y);
  
  int x, y;
  bool passable;  // deduced from Cell entity stack on construction
  int difficulty;    // additional cost to cross
 
  // these operators allow use of pathnode as map keys
  bool operator<(const PathNode& rhs) const;  // for std::map
  bool operator==(const PathNode& rhs) const; // for std::unordered_map
  bool operator!=(const PathNode& rhs) const;
};

#endif // PATHNODE_INCLUDE
