Realiza la operación (a * b) % mod minimizando posibles desbordamientos.

public static long mulmod (long a, long b, long mod) {
  long x = 0;
  long y = a % mod;
  while (b > 0){
    if (b % 2 == 1) x = (x + y) % mod;
    y = (y * 2) % mod;
    b /= 2;
  }
  return x % mod;
}