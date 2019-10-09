Calculo del mínimo común múltiplo usando el máximo común divisor.

/// O(log(max(a, b)))
int lcm(int a, int b) {
    return a*b / __gcd(a, b);
}
