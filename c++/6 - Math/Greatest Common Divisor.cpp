Calcula el máximo común divisor entre a y b mediante el algoritmo de Euclides.

/// O(log(max(a, b)))
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
