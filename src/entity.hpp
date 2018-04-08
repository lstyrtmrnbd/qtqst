#ifndef ENTITY_INCLUDE
#define ENTITY_INCLUDE

class Entity {

public:

  Entity();
  void update(double dticks); // in 'ticks': tick/second conversion rate in qtqst.cpp
  void render(double dtime); // in seconds

protected:


};

#endif // ENTITY_INCLUDE
