Realiza la operación (a^b) % mod.

/// O(1), 0 <= a, b < m
ll mulmod(ll a, ll b, ll m) {
	ll r = a*b-(ll)((long double)a*b/m+.5)*m;
	return r < 0 ? r+m : r;
}
/// O(log(e)), 0 <= b < m
ll expmod(ll b, ll e, ll m) {
    if (e == 0) return 1;
    if (e&1) return mulmod(b, expmod(b, e-1, m), m);
    b = expmod(b, e>>1, m);
    return mulmod(b, b, m);
}
