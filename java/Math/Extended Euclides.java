El algoritmo de Euclides extendido retorna el gcd(a, b) y calcula los coeficientes enteros X y Y que satisfacen la ecuación: a*X + b*Y = gcd(a, b).

public static long extendedEuclid(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long aux = extendedEuclid(b, a % b);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
    return aux;
}
