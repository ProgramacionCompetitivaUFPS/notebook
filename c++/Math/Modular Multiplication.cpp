Realiza la operación (a * b) % mod minimizando posibles desbordamientos.

long long mulmod (long long a, long long b, long long mod) {
  long long x = 0;
  long long y = a % mod;
  while (b > 0){
    if (b % 2 == 1) x = (x + y) % mod;
    y = (y * 2) % mod;
    b /= 2;
  }
  return x % mod;
}