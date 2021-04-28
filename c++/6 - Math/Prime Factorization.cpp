Tres funciones diferentes que guardan en el map f los pares <primo, exponente> de la descomposicion en factores primos de n.

1.1) Iterando hasta sqrt(n)
/// O(sqrt(n))
void fact(ll n, map<ll, int> &f) {
    for (int p = 2; 1ll*p*p <= n; p++)
        while (n%p == 0) f[p]++, n /= p;
    if (n > 1) f[n]++;
}

1.2) Funcion anterior optimizada. Precalcular los primos <= sqrt(n) (con Sieve of Eratosthenes) y en el for iterar sobre los numeros primos.
/// O(sqrt(n)/log(sqrt(n)))

2.1) Utilizando Pollard Rho y Miller Rabin. Agregar estas funciones.
/// O(k * (n^(1/4) + log(n))) donde k es la cantidad de factores primos distintos
void fact(ll n, map<ll, int> &f) {
    if (n == 1) return;
    if (is_prime(n)) { f[n]++; return; }
    ll q = rho(n);
    fact(q, f); fact(n/q, f);
}

2.2) Funcion anterior optimizada. Precalculando los factores con la Sieve of Eratosthenes del siguiente metodo.

void fact(ll n, map<ll, int> &f) {
    for (auto &p : f) while (n%p.F == 0) { p.S++; n /= p.F; }
    if (n <= MX) while (n > 1) { f[prime[n]]++; n /= prime[n]; }
    else if (is_prime(n)) f[n]++;
    else { ll q = rho(n); fact(q, f); fact(n/q, f); }
}

3) Precalculando los factores con Sieve of Eratosthenes (solo para n <= 1e6 aprox).

const int MX = 1e6;
int prime[MX+1];
/// O(MX log(log(MX)))
void sieve() {
    for (int i = 2; i <= MX; i++) {
        if (prime[i]) continue;
        prime[i] = i;
        for (ll j = 1ll*i*i; j <= MX; j += i) {
            if (!prime[j]) prime[j] = i;
        }
    }
}
/// O(log(n))
void fact(int n, map<int, int> &f) {
    while (n > 1) {
        f[prime[n]]++;
        n /= prime[n];
    }
}