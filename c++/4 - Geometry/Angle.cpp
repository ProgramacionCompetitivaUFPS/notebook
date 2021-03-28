Calcula el angulo de una linea con respecto a otra.

lf get_ang(pt a, pt b) {
    lf ang = acos(max(lf(-1.0), min(lf(1.0), lf(dot(a,b))/abs(a)/abs(b))));
    ang = ang * 180.0 / acos(-1.0);
    if (b.y < 0) ang = lf(360) - ang;
    return ang;
}

lf angle(pt a, pt b) {
    pt xo = {1, 0};
    lf ang = get_ang(xo, b) - get_ang(xo, a);
    if (ang < 0) ang += 360;
    return ang;
}

double DegToRad(double d) { 
	return d * acos(-1.0) / 180.0; 
}

double RadToDeg(double r) { 
	return r * 180.0 / acos(-1.0); 
}
