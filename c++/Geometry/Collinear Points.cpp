Determina si el punto r está en la misma linea que los puntos p y q. IMPORTANTE: Deben incluirse las estructuras point y vec.


double cross(vec a, vec b) { 
	return a.x * b.y - a.y * b.x; 
}
bool collinear(point p, point q, point r) {
	return fabs(cross(toVector(p, q), toVector(p, r))) < 1e-9; 
}
