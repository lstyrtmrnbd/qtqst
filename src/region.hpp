#ifndef REGION_INCLUDE
#define REGION_INCLUDE

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

  Environment* environment; // defines the sprites in the region
  bool isActive; // events in this region are being simulated

  
};

#endif // REGION_INCLUDE
