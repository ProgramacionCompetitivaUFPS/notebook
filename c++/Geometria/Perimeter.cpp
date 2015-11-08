Calcula el per\'imetro de un pol\'igono representado como un vector de puntos. IMPORTANTE: Definir P[0] = P[n-1] para cerrar el pol\'igono. La estructura point debe estar definida, al igual que el m\'etodo euclideanDistance.

#include <vector>

double perimeter(vector<point> P) {
	double result = 0.0;
  	for (int i = 0; i < P.size()-1; i++){
    	result += euclideanDistance(P[i], P[i+1]);
  	}
  	return result; 
}

