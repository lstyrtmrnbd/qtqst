#include "region.hpp"

Region::Region(int left, int top, int right, int bottom): left(left), top(top), right(right), bottom(bottom) {

  environment = NULL;
}

Region::~Region() {

  //delete batch; // ??
}

bool Region::isActive() {

  return activeRegion;
}

void Region::buildBatch() {

  if(environment == NULL) return; //log error too please, this shouldn't happen

  std::vector<std::vector<Cell>>::iterator y;
  std::vector<Cell>::iterator x;

  std::vector<std::vector<Cell>>::iterator yLimit = cells->begin() + bottom;
  std::vector<Cell>::iterator xLimit = yLimit->begin() + right;
  
  for(y = (cells->begin() + top); y <= yLimit + 1; y++) {

    for(x = (y->begin() + left); x <= xLimit + 1; x++) {

      
    }
  }
}
