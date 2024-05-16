Dados dos puntos A y B, crea el vector A->B. IMPORTANTE: Debe definirse la estructura point. Es llamado vec para no confundirlo con el vector propio de c++.


struct vec { 
    double x, y;  
  vec(double _x, double _y) : x(_x), y(_y) {} 
};

vec toVector(point a, point b) {       
    return vec(b.x - a.x, b.y - a.y); 
}
