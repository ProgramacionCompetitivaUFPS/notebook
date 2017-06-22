Calcula el area de un polígono representado como un vector de puntos. IMPORTANTE: Definir P[0] = P[n-1] para cerrar el polígono. El algorítmo utiliza el metodo de determinante de la matriz de puntos de la figura. IMPORTANTE: Debe definirse previamente la estructura point.

#include <vector>
#include <cmath>

double area(vector<point> P) {
	double result = 0.0;
  for (int i = 0; i < P.size()-1; i++) {
  	result += ((P[i].x * P[i + 1].y) - (P[i + 1].x * P[i].y));
  }
	return fabs(result) / 2.0; 
}
