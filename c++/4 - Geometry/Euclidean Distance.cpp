Halla la distancia euclideana de 2 puntos en dos dimensiones (x,y). Para usar el primer método, debe definirse previamente la estructura point

#include <cmath>

/*Trabajando con estructuras de tipo punto*/
double euclideanDistance(point p1, point p2) {           
  return hypot(p1.x - p2.x, p1.y - p2.y); 
} 

/*Trabajando con los valores x y y de cada punto*/
double euclideanDistance(double x1, double y1, double x2, double y2){           
  return hypot(x1 - x2, y1 - y2); 
} 
