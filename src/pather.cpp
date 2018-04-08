#include "pather.hpp"

PathGraph* Pather::parseRegion(Region& region) {

  PathGraph* newGraph = new PathGraph();

  // fill graph
  region.doRegionCells([&](Cell& cell, int cellX, int cellY) {

      int x = cellX; int y = cellY;
      int n = cellY + 1;
      int s = cellY - 1;
      int e = cellX + 1;
      int w = cellX - 1;
      
      Cell* north = region.getRelativeCell(x, n);
      Cell* south = region.getRelativeCell(x, s);
      Cell* east = region.getRelativeCell(e, y);
      Cell* west = region.getRelativeCell(w, y);

      Cell* northeast = region.getRelativeCell(e, n);
      Cell* northwest = region.getRelativeCell(w, n);
      Cell* southeast = region.getRelativeCell(e, s);
      Cell* southwest = region.getRelativeCell(w, s);

      PathNode here(cell, x, y);
      
      if(north != nullptr) newGraph->pushNeighbor(here, PathNode(*north, x, n));
      if(south != nullptr) newGraph->pushNeighbor(here, PathNode(*south, x, s));
      if(east != nullptr) newGraph->pushNeighbor(here, PathNode(*east, e, y));
      if(west != nullptr) newGraph->pushNeighbor(here, PathNode(*west, w, y));

      if(northeast != nullptr) newGraph->pushNeighbor(here, PathNode(*northeast, e, n));
      if(northwest != nullptr) newGraph->pushNeighbor(here, PathNode(*northwest, w, n));
      if(southeast != nullptr) newGraph->pushNeighbor(here, PathNode(*southeast, e, s));
      if(southwest != nullptr) newGraph->pushNeighbor(here, PathNode(*southwest, w, s));

    });
  
  return newGraph;
}

Previousmap* Pather::breadthFirst(PathGraph& graph, int fromX, int fromY) {

  std::queue<PathNode> frontier;
  PathNode start = PathNode(fromX, fromY);
  frontier.push(start);

  Previousmap* cameFrom = new Previousmap;
  cameFrom->insert(std::make_pair(start, start)); // HERE

  while(!frontier.empty()) {

    PathNode current = frontier.front();
    frontier.pop();

    for(PathNode next : graph.getNeighbors(current)) {
      
      if(cameFrom->find(next) == cameFrom->end()) {

        frontier.push(next);
        cameFrom->insert(std::make_pair(next, current)); // and HERE
      }
    }
  }
  
  return cameFrom;
}

Path* Pather::pathFromPrevious(Previousmap& prev, int startX, int startY) {

  Path* path = new Path();
  PathNode current = PathNode(startX, startY);

  auto vpit = prev.find(current); // iterator to next node in path

  // while iterator is valid and next node != current
  while( vpit != prev.end() && (*vpit).second != current) {

    path->push_back(std::make_pair(current.x, current.y));
    current = (*vpit).second;
    vpit = prev.find(current);
  }

  return path;
}

void Pather::doPath(Path& path, std::function<void(int x, int y)> fp) {

  for(auto it = path.begin(); it != path.end(); ++it) {

    std::pair<int, int>& p = *it;    
    fp(p.first, p.second);
  }
}
