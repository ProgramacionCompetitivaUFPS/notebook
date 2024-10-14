typedef double T;
const double PI = acos(-1.0);
const double EPS = 1e-9;
//test for equality: DON'T use "a==b" 
//abs(a-b) < EPS;    // or 
//abs(a/b - 1) < EPS;   // make sure b != 0, or even anywhere near it 
 
//test for >=: Don't use "a >= b" 
//a > b-EPS; 
 
//test for >: Don't use "a > b" 
//a >= b+EPS; 

struct pt{
	T x, y;
	
	pt operator + (pt p){return {x + p.x, y + p.y};}
	pt operator - (pt p){return {x - p.x, y - p.y};}
	pt operator * (T d){return {x*d, y*d};}
	pt operator * (pt p){return {x*p.x - y*p.y, x*p.y + y*p.x};}
	pt operator / (T d){return {x/d, y/d};}
	bool operator == (pt b) {return x == b.x && y == b.y;}
	bool operator != (pt b) {return x != b.x || y != b.y;}	
};

bool comp(pt a, pt b) {
	if(b.x == a.x) return a.y < b.y;
	return a.x < b.x;
}

T sq(pt p){return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}

pt translate(pt p, pt v) {return p+v;} //Traslada p con base en el vector v
pt scale(pt c, double factor, pt p) { //Escala un vector p con base a el punto c un factor
	return c + (p-c)*factor;
}
pt rotate(pt p, double a){ //Rota a radianes un punto
	return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

pt perp(pt p){ //Rota 90 grados en sentido antihorario
	return {-p.y, p.x};
}

//pt linearTransform(pt p, pt q, pt r, pt fp, pt fq){ // idk ??????
	//return fp + (r-p)*(fq-fp)/(q-p);
//}

//Si es igual a 0 son perpendiculares dado que dot(p,q) = |p|*|q|*cos(a)
T dot(pt v, pt w){return v.x*w.x+v.y*w.y;} 
bool isPerp(pt v, pt w) {return dot(v,w) == 0;}

double angle(pt v, pt w){ //Retorna el angulo
	double coseno = dot(v, w)/abs(v) / abs(w);
	return acos(max(-1.0, min(1.0, coseno)));
	//return acos(clamp(coseno, -1, 1)); //Clamp permite mantener el valor de coseno en un rango
		//Se usa el rango [-1, 1] porque acos podria tener fallos de precision con numeros mayores
}

//Indica que tan perpendiculares son los vectores
//cross(v, w) == -cross(w, v)
//si es igual 0, son paralelos los vectores
//Si es mayor a 0, el angulo entre los vectores abre en sentido antihorario
//Si es menor a 0, el angulo entre los vectores abre en sentido horario
T cross(pt v, pt w){return v.x*w.y - v.y*w.x;} 

T orient(pt a, pt b, pt c){
	return cross(b-a, c-a); // ans = 0, si son colineares
									// ans > 0, los puntos estan en sentido antihorario
									// ans < 0, los puntos estan en sentido horario

}

//Puede ser util si queremos saber si un punto esta entre el angulo
//que forman dos vectores

bool isAngle(pt a, pt b, pt c, pt p){
	assert(orient(a,b,c) != 0); //no tendria sentido la pregunta si son colineares
	if (orient(a,b,c) < 0) swap(b,c); //Por conveniencia si no tocaria validar mas cosas despues
	return orient(a, p, c) >= 0 && orient(a, b, p) >= 0;
	//return orient(a,b,p) >= 0 && orient(a,c,p) <= 0; esta tambien vale
	//Tecnicamente hay varias maneras de validarlo
}

//Retorna el angulo de apertura siempre en sentido antihorario
double orientedAngle(pt a, pt b, pt c){
	if(orient(a, b, c) >= 0) return angle(b-a, c-a); 
	return 2*PI - angle(b-a, c-a);
}

bool isConvex(vector<pt> p){
	bool hasPos = false;
	bool hasNeg = false;
	for(int i=0, n = p.size(); i<n; i++){
		int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]); 	//Se calcula los productos cruz de puntos consecutivos
		if(o > 0) hasPos = true;								//Todos son pos o neg si es convexo.
		if(o < 0) hasNeg = true;
	}
	return !(hasPos && hasNeg);
}

//Polar sort 

bool half(pt p){ //Para saber si esta en la mitad superior o inferior
					  //Como se ordena con base en el producto cruz si esta muy lejos el producto cruz da negativo					
	assert(p.x == 0 && p.y == 0); //(0, 0) no esta definido	
	//Arriba si esta entre (0, pi]
	//Abajo si esta entre (-pi, 0]
	//Retorna true si esta arriba
	return p.y > 0 || (p.y == 0 && p.x < 0);
}

void polarSort(vector<pt> &v){
	sort(v.begin(), v.end(), [] (pt v, pt w){
		return make_tuple(half(v), 0) <	
				make_tuple(half(w), cross(v, w));
				//Primero compara si v esta abajo y w en la mitad superior
				//si estan en el mismo sector entonces determina si el producto
				//cruz es mayor a 0.
				//Retorna true si v esta antes que w en el ordenamiento
	});
}

// {half(v), 0, sq(v)} < {half(w), cross(v, w), sq(w)}, 
// si el cross es 0 el elemento menor es el que esta mas cerca


void polarSortAround(pt o, vector<pt> &v){ //Polar sort con respecto a un punto o conviene restar o 
														//a todos los puntos antes de hacer el sort
	for(auto &q: v) q = q-o;
	polarSort(v);
}