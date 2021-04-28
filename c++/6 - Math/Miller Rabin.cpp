El algoritmo de Miller-Rabin determina si un numero es primo o no. Agregar Modular Exponentiation (para m ll) y Modular Multiplication.

/// O(log(n))
bool test(ll n, int a) {
    if (n == a) return true;
    ll s = 0, d = n-1;
    while (d%2 == 0) s++, d /= 2;
    ll x = expmod(a, d, n);
    if (x == 1 || x+1 == n) return true;
    for (int i = 0; i < s-1; i++) {
        x = mulmod(x, x, n);
        if (x == 1) return false;
        if (x+1 == n) return true;
    }
    return false;
}

bool is_prime(ll n) {
    if (n == 1) return false;
    int pr[] = {2,3,5,7,11,13,17,19,23};
    for (auto &p : pr) if (!test(n, p)) return false;
    return true;
}