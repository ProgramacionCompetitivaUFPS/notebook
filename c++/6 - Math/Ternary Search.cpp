Retorna el valor minimo de una funcion entre l y r. Se recomienda usar de 50 a 90 iteraciones.

double f(double x) {
    double y = x; // funcion a evaluar que depende de x
    return y;
}

double ternary_search(double l, double r, int it) {
    double a = (2.0*l + r)/3.0;
    double b = (l + 2.0*r)/3.0;
    if (it == 0) return f(a);
    if (f(a) < f(b)) return ternary_search(l, b, it-1);
    return ternary_search(a, r, it-1);
}
