La función Rho de Pollard calcula un divisor no trivial de n. IMPORTANTE: Deben implementarse Modular Multiplication y Gratest Common Divisor (para long long).

long long pollardRho (long long n) {
  int i = 0, k = 2;
  long long d, x = 3, y = 3;
  while (true) {
    i++;
    x = (mulmod(x, x, n) + n - 1) % n;
    d = mcd(abs(y - x), n);
    if (d != 1 && d != n) return d;
    if (i == k) {
      y = x;
      k *= 2;
    }
  }
}