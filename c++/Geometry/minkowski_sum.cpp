void ordMinY(vector<pt> &pts){
	int pos = 0;
	for(int i=0; i<(int)pts.size(); i++){
		if(pts[i].y < pts[pos].y || (pts[i].y == pts[pos].y && pts[i].x < pts[pos].x)){
			pos = i;
		}
	}
	rotate(pts.begin(), pts.begin() + pos, pts.end());
}

vector<pt> minkowski(vector<pt> a, vector<pt> b){
	ordMinY(a); ordMinY(b);
	vector<pt> sum;
	a.push_back(a[0]); a.push_back(a[1]);
	b.push_back(b[0]); b.push_back(b[1]);
	int i = 0, j = 0;
	while(i < (int)a.size() - 2 || j < (int)b.size() - 2){
		sum.push_back(a[i] + b[j]);
		ll crp = cross(a[i+1] - a[i], b[j+1] - b[j]);
		if(crp >= 0 && i < (int)a.size() - 2){
			i++;
		} 
		if(crp <= 0 && j < (int)b.size() - 2){
			j++;
		} 
	}
	return sum;
}