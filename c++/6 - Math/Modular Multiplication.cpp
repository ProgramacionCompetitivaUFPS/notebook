Realiza la operación (a*b) % mod minimizando posibles desbordamientos.

long long modmul(long long a, long long b, long long mod) {
    if (b == 0) return 0;
    if (b&1) return (a + modmul(a, b-1, mod)) % mod;
    long long c = modmul(a, b/2, mod);
    return (c+c) % mod;
}
