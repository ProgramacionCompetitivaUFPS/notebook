Retorna el valor máximo de una función f(x) entre [l, r]

const double eps = 1e-9;

double ternary_search(double l, double r) {
    while (r - l > eps) { // O se pueden hacer unas 100 iteraciones
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1 < f2) l = m1;
        else r = m2;
    }
    return f(l);
}
