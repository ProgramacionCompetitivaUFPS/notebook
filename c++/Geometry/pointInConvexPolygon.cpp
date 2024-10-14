bool pointInTriangle(pt a, pt b, pt c, pt p){
	ll s1 = abs(cross(b - a, c - a));
	ll s2 = abs(cross(b - a, p - a)) + abs(cross(p - a, c - a)) + abs(cross(b - p, c - p));
	return s1 == s2;
}

bool pointInConvexPolygon(vector<pt> &pts, pt p){
	//Podrias mover todos los puntos con respecto a 
	//pts[0] antes de hacer esto, eso reduce el codigo
	int n = pts.size();
	if(cross(pts[1] - pts[0], p - pts[0]) >= 0 && cross(p - pts[0], pts[n-1] - pts[0]) >= 0){
		if(cross(pts[1] - pts[0], p - pts[0]) == 0){
			return sq(p - pts[0]) <= sq(pts[1] - pts[0]);
		}
		if(cross(pts[n-1] - pts[0], p - pts[0]) == 0){
			return sq(p - pts[0]) <= sq(pts[n-1] - pts[0]);
		}	
		int l = 1, r = n-1;
		while(l <= r){
			int mid = (l+r)/2;
			if(cross(pts[mid] - pts[0], p - pts[0]) >= 0){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		if(r == 0) return false;
		return pointInTriangle(pts[0], pts[r], pts[r+1], p); 
	}
	return false;
}