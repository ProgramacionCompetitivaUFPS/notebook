Determina si un punto pt se encuentra en el pol\'igono P. Este pol\'igono se define como un vector de puntos, donde el punto 0 y n-1 son el mismo. IMPORTANTE: Deben incluirse las estructuras point y vec, ademas del m\'etodo angle.

#include <cmath>

bool ccw(point p, point q, point r) {
  return cross(toVector(p, q), toVector(p, r)) > 0; }
  
bool inPolygon(point pt, vector<point> P) {
	if (P.size() == 0){
  		return false;
  	} 
  	double sum = 0;    
  	for (int i = 0; i < P.size()-1; i++) {
    	if (ccw(pt, P[i], P[i+1])){
    		sum += angle(P[i], pt, P[i+1]); 
    	}else{
    		sum -= angle(P[i], pt, P[i+1]);
    	}
    }
  	return fabs(fabs(sum) - 2*acos(-1.0)) < 1e-9; 
}
