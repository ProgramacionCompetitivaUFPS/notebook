Calcula fibonacci(n) % m.

/// O(log(n))
int fibmod(ll n, int m) {
    int a = 0, b = 1, c;
    for (int i = 63-__builtin_clzll(n); i >= 0; i--) {
        c = a;
        a = (1ll*c*(2ll*b-c+m)) % m;
        b = (1ll*c*c + 1ll*b*b) % m;
        if ((n>>i) & 1) {
            c = (a+b) % m;
            a = b; b = c;
        }
    }
    return a;
}
