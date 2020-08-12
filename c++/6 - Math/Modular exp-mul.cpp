En ambas funciones a y b deben estar ya con modulo m.

* Calcular (a*b) % m sin overflow.
/// O(1)
ll mul(ll a, ll b, ll m) {
	ll r = a*b-(ll)((long double)a*b/m+.5)*m;
	return r < 0 ? r+m : r;
}

* Calcular (b^e) % m (e puede ser ll). Si m es ll usar mul() sin overflow.
/// O(log(e))
int pow(int b, int e, int m) {
    int ans = 1;
    while (e) {
        if (e&1) ans = (1ll*ans*b) % m;
        b = (1ll*b*b) % m;
        e /= 2;
    }
    return ans;
}
