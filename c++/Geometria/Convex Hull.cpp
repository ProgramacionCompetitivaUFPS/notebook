Retorna el pol\ígono convexo mas pequeño que cubre (ya sea en el borde o en el interior) un set de puntos. Recibe un vector de puntos, y retorna un vector de puntos indicando el pol\'igono resultante. Es necesario que esten definidos previamente: 

Estructuras: point y vec
M\'etodos: collinear, euclideanDistance, inPolygon y angle.


#include <cmath>
#include <algorithm>
#include <vector>

point pivot;
bool angleCmp(point a, point b) {                
	if (collinear(pivot, a, b)){
		return euclideanDistance(pivot, a) < euclideanDistance(pivot, b);
	}                              
        
  	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; 
}


vector<point> convexHull(vector<point> P) {  
  	int i, j, n = P.size();
  	if (n <= 3) {
    	if (!(P[0] == P[n-1])){
    		P.push_back(P[0]);
    	}  
    	return P;
  	}
  	int P0 = 0;
  	for (i = 1; i < n; i++){
  		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)){
  	 		P0 = i;
  	 	}
  	}

  	point temp = P[0]; P[0] = P[P0]; P[P0] = temp; 
	pivot = P[0];
  	sort(++P.begin(), P.end(), angleCmp);     
	vector<point> S;
  	S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   
  	i = 2;                                         
  	while (i < n) {           
    	j = S.size()-1;
    	if (ccw(S[j-1], S[j], P[i])){
    		S.push_back(P[i++]);
    	}else{
    		S.pop_back();
    	}  
    }  
  	return S; 
}  
