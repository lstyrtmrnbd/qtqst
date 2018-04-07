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

Pathlist* Pather::breadthFirst(PathGraph& graph, int startX, int startY) {

  std::queue<PathNode> frontier();

  frontier.push(PathNode(startX, startY));

  Pathlist* cameFrom = new Pathlist();

  while(!frontier.empty()) {

    PathNode current = frontier.front();
    frontier.pop();

    for(PathNode next : graph.getNeighbors(current)) {

      std::pair<int, int> pathLoc(next.x, next.y);
      
      if(cameFrom.find(pathLoc) == cameFrom.end()) {

        frontier.push(next);
        cameFrom[pathLoc] = std::pair<int, int>(current.x, current.y);
      }
    }
  }
  
  return cameFrom;
}
