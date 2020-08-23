La funcion Rho de Pollard calcula un divisor no trivial de n. Agregar Modular Multiplication.

ll rho(ll n) {
    if(!(n&1)) return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand() % n + 1;
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = __gcd(abs(x-y), n);
    }
    return d == n ? rho(n) : d;
}