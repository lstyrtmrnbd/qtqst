#include "entity.hpp"

Entity::Entity(Cell* currentCell): currentCell(currentCell) {

}

//dt is in 'ticks', don't forget it
void Entity::updateGameLogic(double dt) {

  move(dt);
}

void Entity::move(double dt) {

}
