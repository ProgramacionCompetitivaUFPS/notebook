Guarda en f los factores primos de n con sus exponentes.

/// O(sqrt(n))
void fact(ll n, map<ll, int>& f) {
    for (ll p = 2; p*p <= n; p++)
        while (n%p == 0) f[p]++, n /= p;
    if (n > 1) f[n]++;
}

* Agregar Pollard Rho y Miller Rabin.

void fact(ll n, map<ll, int>& f) {
    if (n == 1) return;
    if (isPrime(n)) { f[n]++; return; }
    ll q = rho(n);
    fact(q, f); fact(n/q, f);
}

* Precalculando los factores con Sieve of Eratosthenes (solo para int).

const int MAX = 10000000;
int prime[MAX+1];
/// O(MAX log(log(MAX)))
void sieve() {
    for (int i = 2; i <= MAX; i++) if (!prime[i]) {
        prime[i] = i;
        for (ll j = 1ll*i*i; j <= MAX; j += i) {
            if (!prime[j]) prime[j] = i;
        }
    }
}
/// O(log(n))
void fact(int n, map<int, int>& f) {
    while (n != 1) {
        f[prime[n]]++;
        n /= prime[n];
    }
}
