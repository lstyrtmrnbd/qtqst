#ifndef REGION_INCLUDE
#define REGION_INCLUDE

class Region {

public:

  Region();
  
private:

  // these are the subscripts into the cell array that define the region
  int top;
  int left;
  int bottom;
  int right;
  Environment* environment; // defines the sprites in the region
  bool isActive; // events in this region are being simulated

  
};

#endif // REGION_INCLUDE
