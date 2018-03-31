#ifndef REGION_INCLUDE
#define REGION_INCLUDE

#include <vector>
#include <iterator>

#include "cell.hpp"
#include "environment.hpp"
#include "SpriteBatch.hpp"
#include "Sprite.hpp"

/**
 * -Holds a pointer to its parent Level's cells
 * -    but should only ever operate within its own defined subscripts! 
 * -Holds info for rendering terrain in the cells it references
 * -Holds pointers to entities that exist in its cells, so it can render them
 * -    this is maintained by Level.update() of its parent level
 */

class Region {

public:

  Region(int left, int top, int right, int bottom);

  ~Region();

  void setEnvironment(Environment*);
  bool isActive();
  void buildBatch(); // consults environment to fill batch

  void update(double dticks);
  void render(double dtime);
  
private:

  // these are the subscripts into the cell array that define the region
  int left;
  int top;
  int right;
  int bottom;

  int width;
  int height;
  
  bool activeRegion = true; // events in this region are being simulated

  std::vector<std::vector<Cell>>* cells; // a reference to its parent Level's cell grid
  Environment* environment;              // defines how to get the static sprites for the region
  
  std::vector<swift::Sprite>* staticSprites; // holds the Sprites attached to batch
  swift::SpriteBatch* batch;                 // holds the static SpriteBatch, drawn in render()

};

#endif // REGION_INCLUDE
