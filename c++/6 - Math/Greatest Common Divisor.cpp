Calcula el maximo comun divisor entre a y b mediante el algoritmo de Euclides. Tambien se puede usar __gcd(a, b).

// O(log(max(a, b)))
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
