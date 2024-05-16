struct halfplane{
    double angle;
    pt p, pq;
    halfplane(){}
    halfplane(pt a, pt b): p(a), pq(b - a) {
        angle = atan2(pq.y,pq.x);
    }
    bool operator < (halfplane b)const{return angle < b.angle;}
    bool out(pt q){return cross(pq, (q-p)) < -eps;} // checks if p is inside the half plane
};

const lf inf = 1e100;
// intersection pt of the lines of 2 halfplanes
pt inter(halfplane& h1, halfplane& h2){
    if(abs(cross(unit(h1.pq), unit(h2.pq))) <= eps)return {inf, inf};
    lf alpha = cross((h2.p - h1.p), h2.pq) / cross(h1.pq, h2.pq);
    return h1.p + (h1.pq * alpha);
}

// intersection of halfplanes
vector<pt> intersect(vector<halfplane>& b){
    vector<pt> box = { {inf, inf}, {-inf, inf}, {-inf, -inf}, {inf, -inf} };
    for(int i = 0; i < 4; i++){
        b.push_back({box[i], box[(i + 1) % 4]});
    }
    sort(b.begin(), b.end());
    int n = b.size(), q = 1, h = 0;
    vector<halfplane> c(n + 10);
    for(int i = 0; i < n; i++){
        while(q < h && b[i].out(inter(c[h], c[h-1]))) h--;
        while(q < h && b[i].out(inter(c[q], c[q+1]))) q++;
        c[++h] = b[i];
        if(q < h && abs(cross(c[h].pq, c[h-1].pq)) < eps){
            if(dot(c[h].pq, c[h-1].pq) <= 0) return {};
            h--;
            if(b[i].out(c[h].p)) c[h] = b[i];
        }
    }
    while(q < h-1 && c[q].out(inter(c[h], c[h-1]))) h--;
    while(q < h-1 && c[h].out(inter(c[q], c[q+1]))) q++;
    if(h - q <= 1)return {};
    c[h+1] = c[q];
    vector<pt> s;
    for(int i = q; i < h+1; i++) s.pb(inter(c[i], c[i+1]));
    return s;
}