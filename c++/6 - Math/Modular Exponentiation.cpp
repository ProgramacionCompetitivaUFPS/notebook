Realiza la operación (a^b) % mod.

long long modpow(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    if (b&1) return (a * modpow(a, b-1, mod)) % mod;
    long long c = modpow(a, b/2, mod);
    return (c*c) % mod;
}
