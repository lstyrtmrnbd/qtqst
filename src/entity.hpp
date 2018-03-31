#ifndef ENTITY_INCLUDE
#define ENTITY_INCLUDE

#include "cell.hpp"

class Entity {

public:

  Entity(Cell* currentCell);
  void updateGameLogic(double dt); //measured in 'ticks': tick/second conversion rate in qtqst.cpp
  void updateRendition(double dt); //i.e. 'draw', this one is measured in seconds!!
  
private:

  Cell* targetCell;
  Cell* nextCell;
  Cell* currentCell;
  double movementProgress; //percentage progress between currentCell and nextCell

  double speed; //rate of movement between two tiles
  
  void move(double dt); //called during update to progress movement, dt is in 'ticks'
};

#endif ENTITY_INCLUDE
