#ifndef PATHER_INCLUDE
#define PATHER_INCLUDE

#include <functional>
#include <queue>

#include "pathgraph.hpp"
#include "pathnode.hpp"
#include "region.hpp"

// mapping of nodes to the node visited before them
// keys are considered equivalent if std::map::key_comp returns false reflexively
using Previousmap = std::map<PathNode, PathNode>;

// sequence of x, y values defining a path
using Path = std::vector<std::pair<int, int>>;

class Pather {

 public:

  static PathGraph* parseRegion(Region&);
  static Previousmap* breadthFirst(PathGraph&, int, int);
  static Path* pathFromPrevious(Previousmap&, int, int);
  static void doPath(Path&, std::function<void(int x, int y)>);
  
 private:

  std::priority_queue<PathNode> pq;
};

#endif // PATHER_INCLUDE
