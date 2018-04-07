#ifndef MOVER_INCLUDE
#define MOVER_INCLUDE

#include "cell.hpp"
#include "entity.hpp"

/**
 *These things live in Cells and move between them
 */
class Mover {

public:

  Mover(Cell* currentCell);
  void move(double dticks); //called during update to progress movement
  double getMovementProgress(); // whatever's in charge of drawing will want to know 
  
private:

  Entity* entity;
  Cell* targetCell;
  Cell* nextCell;
  Cell* currentCell;
  double movementProgress; //percentage progress between currentCell and nextCell

  double speed; //rate of movement between two tiles
  
};

#endif // MOVER_INCLUDE
