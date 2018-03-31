#ifndef REGION_INCLUDE
#define REGION_INCLUDE

#include "environment.hpp"
#include "SpriteBatch.hpp"
#include "Sprite.hpp"

/**
 * -Holds info for rendering terrain in the cells it references
 * -Holds pointers to entities that exist in its cells, so it can render them
 *   -^ this is maintained by Level.update() of its parent level
 */

class Region {

public:

  Region();

  Region(int left, int top, int right, int bottom);

  void setEnvironment(Environment*);
  
private:

  // these are the subscripts into the cell array that define the region
  int left;
  int top;
  int right;
  int bottom;
  
  bool isActive; // events in this region are being simulated

  Environment* environment;  // defines the sprites in the region
  swift::SpriteBatch* batch; // constructed based on the environment

};

#endif // REGION_INCLUDE
