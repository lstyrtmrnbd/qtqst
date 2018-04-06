#ifndef MOVESPIRIT_INCLUDE
#define MOVESPIRIT_INCLUDE

#include "cell.hpp"
#include "entity.hpp"

/**
 *These things live in Cells and move between them
 */
class MoveSpirit {

public:

  MoveSpirit(Cell* currentCell);
  void move(double dticks); //called during update to progress movement
  double getMovementProgress(); // whatever's in charge of drawing me will want to know 
  
private:

  Entity* entity;
  Cell* targetCell;
  Cell* nextCell;
  Cell* currentCell;
  double movementProgress; //percentage progress between currentCell and nextCell

  double speed; //rate of movement between two tiles
  
};

#endif // MOVESPIRIT_INCLUDE
