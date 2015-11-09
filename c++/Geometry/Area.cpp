Calcula el area de un polígono representado como un vector de puntos. IMPORTANTE: Definir P[0] = P[n-1] para cerrar el polígono. El algorítmo utiliza el metodo de determinante de la matriz de puntos de la figura. IMPORTANTE: Debe definirse previamente la estructura point.

#include <vector>
#include <cmath>

double area(vector<point> P) {
	double result = 0.0, x1, y1, x2, y2;
  	for (int i = 0; i < P.size()-1; i++) {
    	x1 = P[i].x; 
    	x2 = P[i+1].x;
    	y1 = P[i].y; 
    	y2 = P[i+1].y;
    	result += ((x1 * y2) - (x2 * y1));
  	}
  	return fabs(result) / 2.0; 
}
