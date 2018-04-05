#ifndef INHABITANT_INCLUDE
#define INHABITANT_INCLUDE

/**
 *These things live in Cells and move between them
 */
class Inhabitant {

public:

  Inhabitant(Cell* currentCell);
  void move(double dticks); //called during update to progress movement
  double getMovementProgress(); // whatever's in charge of drawing me will want to know 
  
private:

  Cell* targetCell;
  Cell* nextCell;
  Cell* currentCell;
  double movementProgress; //percentage progress between currentCell and nextCell

  double speed; //rate of movement between two tiles
  
};

#endif // INHABITANT_INCLUDE
