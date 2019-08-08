Calcula fibonacci(n) % m.

/// O(log(n))
ll fibmod(ll n, ll m) {
    ll a = 0, b = 1, c;
    for (int i = 63-__builtin_clzll(n); i >= 0; i--) {
        c = a;
        a = ((c%m) * (2*(b%m) - (c%m) + m)) % m;
        b = ((c%m) * (c%m) + (b%m) * (b%m)) % m;
        if (((n >> i) & 1) != 0) {
            c = (a + b) % m;
            a = b; b = c;
        }
    }
    return a;
}
