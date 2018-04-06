#ifndef ENTITY_INCLUDE
#define ENTITY_INCLUDE

#include "cell.hpp"

class Entity {

public:

  Entity();
  void update(double dticks); //measured in 'ticks': tick/second conversion rate in qtqst.cpp
  void render(double dtime); //i.e. 'draw', this one is measured in seconds!!

protected:


};

#endif // ENTITY_INCLUDE
