La función de Miller-Rabin determina si un número dado es o no un número primo. Agregar Modular Exponentiation.

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

/// O(k log^3(n))
bool isPrime(ll n) {
    if (n == 1) return false;
    vector<int> ar = {2,3,5,7,11,13,17,19,23};
    for (auto& a : ar) if (!test(n, a)) return false;
    return true;
}
