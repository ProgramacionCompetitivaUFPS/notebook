La función Rho de Pollard calcula un divisor no trivial de n. IMPORTANTE: Deben implementarse Modular Multiplication y Gratest Common Divisor (para long long).

public static long pollardRho (long n) {
  int i = 0, k = 2;
  long d, x = 3, y = 3;
  while (true) {
    i++;
    x = (mulmod(x, x, n) + n - 1) % n;             // generating function
    d = mcd(Math.abs(y - x), n);                   // the key insight
    if (d != 1 && d != n) return d;
    if (i == k) { 
      y = x; 
      k *= 2;
    }
  }
}