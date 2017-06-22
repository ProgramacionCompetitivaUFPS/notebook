La estructura punto será la base sobre la cual se ejecuten otros algoritmos. 

#include <cmath>

struct point { 
	double x, y;
  	point() { x = y = 0.0; }
  	point(double _x, double _y) : x(_x), y(_y) {}        
  	bool operator == (point other) const {
   		return (fabs(x - other.x) < 1e-9 && (fabs(y - other.y) < 1e-9)); 
   	}
};