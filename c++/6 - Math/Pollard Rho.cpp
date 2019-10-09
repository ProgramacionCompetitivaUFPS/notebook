La función Rho de Pollard calcula un divisor no trivial de n. Agregar mulmod() de Modular Exponentiation.

ll rho(ll n) {
    if (!(n&1)) return 2;
    ll i = 0, k = 2, x = 3, y = 3, d;
    while (true) {
        x = (mulmod(x, x, n) + n - 1) % n;
        d = __gcd(abs(y - x), n);
        if (d != 1 && d != n) return d;
        if (++i == k) y = x, k <<= 1;
    }
}
