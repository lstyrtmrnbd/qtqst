#include "pather.hpp"
/**
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
*/

PathGraph* Pather::parseRegion(Region& region) {

  PathGraph* newGraph = new PathGraph();

  // instantiate graph nodes
  region.doRegionCells([&](Cell& cell, int cellX, int cellY) {

    });

  // fill graph pointer vectors
  // rather iterate over the pathgraph vector
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

    });
}

Previousmap* Pather::breadthFirst(PathGraph& graph, int fromX, int fromY) {

  // -1 is default value and means pair hasn't been visited
  Previousmap* cameFrom = new Previousmap(height, Previousrow(width, std::make_pair(-1, -1)));
  
  std::queue<PathNode*> frontier;
  
  std::unique_ptr<PathNode> start(new PathNode(fromX, fromY));
  frontier.push(start.get());

  //cameFrom->insert(std::make_pair(start, start)); // HERE
  cameFrom->at(fromY).at(fromX) = std::make_pair(fromX, fromY);

  while(!frontier.empty()) {

    PathNode* current = frontier.front();
    frontier.pop();

    for(PathNode* next : graph.getNeighbors(current)) {

      /**
      if(find(*next) == cameFrom->end()) {

        frontier.push(next);
        cameFrom->insert(std::make_pair(next, current)); // and HERE
      }
      */

      std::pair<int, int>& value = cameFrom->at(next->y).at(next->x);

      if(value.first == -1 && value.second == -1) {

        frontier.push(next);
        value = std::make_pair(current->x, current->y);
      }

    }

    std::cout << "breadthFirst filled prevMap: " << cameFrom->size() << "\n";
  }
  
  return cameFrom;
}

Path* Pather::pathFromPrevious(Previousmap& prev, int startX, int startY) {

  Path* path = new Path();
  PathNode current = PathNode(startX, startY);

  auto vpit = prev.find(current); // iterator to next node in path

  // while iterator is valid and next node != current
  while( vpit != prev.end() && vpit->second != current) {

    path->push_back(std::make_pair(current.x, current.y));
    current = vpit->second;
    vpit = prev.find(current);
  }

  return path;
}

void Pather::doPath(Path& path, std::function<void(int x, int y)> fp) {

  for(auto it = path.begin(); it != path.end(); ++it) {
    
    fp(it->first, it->second);
  }
}
