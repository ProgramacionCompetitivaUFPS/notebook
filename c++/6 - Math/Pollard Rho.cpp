La funcion Rho de Pollard calcula un divisor no trivial de n. Agregar Modular Multiplication.

ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }

ll rho(ll n) {
    if (!(n&1)) return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand() % n + 1;
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = gcd(abs(x-y), n);
    }
    return d == n ? rho(n) : d;
}

* Version optimizada

ll add(ll a, ll b, ll m) { return (a += b) < m ? a : a-m; }

ll rho(ll n) {
    static ll s[MX];
    while (1) {
        ll x = rand()%n, y = x, c = rand()%n;
        ll *px = s, *py = s, v = 0, p = 1;
        while (1) {
            *py++ = y = add(mulmod(y, y, n), c, n);
            *py++ = y = add(mulmod(y, y, n), c, n);
            if ((x = *px++) == y) break;
            ll t = p;
            p = mulmod(p, abs(y-x), n);
            if (!p) return gcd(t, n);
            if (++v == 26) {
                if ((p = gcd(p, n)) > 1 && p < n) return p;
                v = 0;
            }
        }
        if (v && (p = gcd(p, n)) > 1 && p < n) return p;
    }
}
