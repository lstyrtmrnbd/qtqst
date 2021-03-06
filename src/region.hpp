#ifndef REGION_INCLUDE
#define REGION_INCLUDE

#include <vector>
#include <iterator>
#include <iostream>
#include <functional>

#include "cell.hpp"
#include "entity.hpp"
#include "environment.hpp"
#include "SpriteBatch.hpp"
#include "Sprite.hpp"

/**
 * -Holds a pointer to its parent Level's cells
 * -    but should only ever operate within its own defined subscripts! 
 * -Holds info for rendering terrain in the cells it references
 * ---
 * -Holds pointers to entities that exist in its cells, so it can render them?
 * -    this is maintained by Level.update() of its parent level?
 * -Rather it could just access them out of the cells...
 */
class Region {

public:

  Region(int left, int top, int right, int bottom,
         std::vector<std::vector<Cell>>* cells);

  ~Region();

  void setEnvironment(Environment* environment);
  void buildBatch(); // consults environment to fill batch with static sprites
  void rebuildBatch();
  void doRegionCells(std::function<void(Cell&, int, int)>); // cell, cellX, cellY

  bool isActive();
  swift::SpriteBatch& getBatch();
  swift::Sprite& getStaticSprite(unsigned int index);
  std::vector<std::vector<Cell>>* getLevelCells();
  int getWidth();
  int getHeight();
  Cell* getRelativeCell(int x, int y); // eg. (0,0) is top left of region, returns nullptr on out of bounds

  void update(double dticks);
  void render(double dtime, sf::RenderWindow& window);

  friend std::ostream& operator<<(std::ostream&, const Region&);
  
private:

  // these are the subscripts into the cell array that define the region
  // the origin is in the top left, so right > left & bottom > top
  int left;
  int top;
  int right;
  int bottom;

  int width;
  int height;
  
  bool activeRegion = true; // events in this region are being simulated

  std::vector<std::vector<Cell>>* cells; // a pointer to its parent Level's cell grid
  Environment* environment;              // defines the local terrain : sprites mapping
  
  std::vector<swift::Sprite*>* staticSprites; // holds the Sprites attached to batch
  swift::SpriteBatch* batch;                 // the static sprite batch, drawn in render()

};

#endif // REGION_INCLUDE
