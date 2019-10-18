La función phi de Euler devuelve la cantidad de enteros positivos menores o iguales a n que son coprimos con n (gcd(n, i) = 1)

/// O(sqrt(n))
ll phi(ll n) {
    ll ans = n;
    for (ll p = 2; p*p <= n; p++) {
        if (n % p == 0) ans -= ans / p;
        while (n % p == 0) n /= p;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

* Calcular el Euler totient para todos los numeros menores o iguales a MAX con Sieve of Eratosthenes.

const int MAX = 10000000;
int phi[MAX+1];
bitset<MAX+1> marked;
///  O(MAX log(log(MAX)))
void sieve() {
    iota(phi, phi+MAX+1, 0);
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MAX; i++) if (!marked[i]) {
        for (int j = i; j <= MAX ; j += i) {
            phi[j] -= phi[j] / i;
            marked[j] = true;
        }
        marked[i] = false;
    }
}
