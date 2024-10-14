struct line {
	pt v; T c;
	// From direction vector v and offset c
	line(pt v, T c) : v(v), c(c) {} 
	// From equation ax+by=c
	line(T a, T b, T c) : v({b,-a}), c(c) {}
	// From points P and Q
	line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
	// Will be defined later:
	// - these work with T = int
	T side(pt p) {return cross(v,p)-c;} //Algo parecido a orient
	double dist(pt p) {return abs(side(p)) / abs(v);} //Distancia de P a la linea
	line perpThrough(pt p) {return {p, p + perp(v)};} //Linea perpendicular a l

	bool cmpProj(pt p, pt q) { //Comparador para ordenar puntos sobre la linea
		return dot(v,p) < dot(v,q);
	}
	
	line translate(pt t) {return {v, c + cross(v,t)};} //Traslada la linea con base en un vector
	line shiftLeft(double dist) {return {v, c + dist*abs(v)};} //Mueve la linea perpendicularmente una distancia
	// - these require T = double
	pt proj(pt p) {return p - perp(v)*side(p)/sq(v);} //Retorna el punto mas cercano de la linea a p
	pt refl(pt p) {return p - perp(v)*2*side(p)/sq(v);} //Retorna el punto reflejo de p con respecto a la linea

};

bool inter(line l1, line l2, pt &out) { 
	T d = cross(l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating-point coordinates
	return true;
	//Retorna true si se pudo hallar un punto de cruce
	//Determina en que punto se cruzan dos lineas
}


line bisector(line l1, line l2, bool interior) {
	assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
	double sign = interior ? 1 : -1;
	return {l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign,
	l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign};
	//Retorna una linea que forma angulos iguales con las otras dos lines
	//La interna es la que esta entre el vector l1 y l2
	//La externa es la otra
}

double segPoint(pt a, pt b, pt p, pt &ans) {
	if (a != b) {
		line l(a,b);
		if (l.cmpProj(a,p) && l.cmpProj(p,b)){// if closest to projection
			ans = l.proj(p);
			return l.dist(p); // output distance to line
		} 		
	}
	if(abs(p-a) < abs(p-b)) ans = a;
	else ans = b;
	return min(abs(p-a), abs(p-b)); // otherwise distance to A or B
}

double segSeg(pt a, pt b, pt c, pt d) {
	pt ax;
	return min({segPoint(a,b,c,ax), segPoint(a,b,d,ax),
	segPoint(c,d,a,ax), segPoint(c,d,b,ax)});
}

bool inDisk(pt a, pt b, pt p) {
	return dot(a-p, b-p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
	return orient(a,b,p) == 0 && inDisk(a,b,p);
}

bool properInter(pt a, pt b, pt c, pt d, pt &out) {
	double oa = orient(c,d,a), // basado en la orientacion sabemos si se cruzan
	ob = orient(c,d,b),
	oc = orient(a,b,c),
	od = orient(a,b,d);
	// Proper intersection exists iff opposite signs
	if (oa*ob < 0 && oc*od < 0) {
		out = (a*ob - b*oa) / (ob-oa);
		return true;
	}
	return false;
}

//Circulo dado tres puntos
//Es la interseccion del segmento perpendicular
//al segmento AB y del segmento perpendicular a AC
pt circumCenter(pt a, pt b, pt c) {
	b = b-a, c = c-a; // consider coordinates relative to A
	assert(cross(b,c) != 0); // no circumcircle if A,B,C aligned
	return a + perp(b*sq(c) - c*sq(b))/cross(b,c)/2;
}