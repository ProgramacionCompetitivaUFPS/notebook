Realiza la operación (a * b) % mod minimizando posibles desbordamientos.

long long mulmod(long long a, long long b, long long mod) {
    long long x = 0, y = a % mod;
    while (b > 0) {
        if (b % 2 == 1) x = (x + y) % mod;
        y = (y<<1) % mod;
        b >>= 1;
    }
    return x % mod;
}
