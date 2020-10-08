Calculo del minimo comun multiplo usando el maximo comun divisor.

/// O(log(max(a, b)))
int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}