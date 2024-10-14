/*	
	Recibe una lista ordenada de puntos, orden lexicografico.
	Retorna el cuadrado de la distancia más corta entre dos puntos (d*d)
	
	Existe otro algoritmo pero es más complejo de entender.
*/

long long closest_pair(vector<pt> pts){
	set<pair<ll, ll>> cur;
	ll dist = 1e18;
	int j = 0;
	for(int i=0; i<(int) pts.size(); i++){
		ll d = ceil(sqrt(dist));
		while(j <= i && pts[i].x - pts[j].x >= d){
			cur.erase({pts[j].y, pts[j].x});
			j++;
		}
		auto it1 = cur.lower_bound({pts[i].y - d, pts[i].x});
		auto it2 = cur.upper_bound({pts[i].y + d, pts[i].x});
		
		for(auto it = it1; it != it2; it++){
			ll dx = pts[i].x - (*it).second;
			ll dy = pts[i].y - (*it).first;
			dist = min(dist, dx*dx + dy*dy);
		}
		cur.insert({pts[i].y, pts[i].x});
	}
	return dist;
}

T closest_pair_double_ver(vector<pt> &pts){
	set<pair<T, T>> cur;
	T dist = 1e18;
	int j = 0;
	for(int i=0; i<(int) pts.size(); i++){
		while(j <= i && (pts[i].x - pts[j].x) > dist-EPS){
			cur.erase({pts[j].y, pts[j].x});
			j++;
		}
		auto it1 = cur.lower_bound({pts[i].y - dist, pts[i].x});
		auto it2 = cur.upper_bound({pts[i].y + dist, pts[i].x});
		
		for(auto it = it1; it != it2; it++){
			T dx = pts[i].x - (*it).second;
			T dy = pts[i].y - (*it).first;
			dist = min(dist, sqrt(dx*dx + dy*dy));
		}
		cur.insert({pts[i].y, pts[i].x});
	}
	return dist;
}