La funcion phi de Euler devuelve la cantidad de enteros positivos menores o iguales a n que son coprimos con n (gcd(n, i) = 1)

/// O(sqrt(n))
ll phi(ll n) {
    ll ans = n;
    for (int p = 2; p <= n/p; ++p) {
        if (n % p == 0) ans -= ans / p;
        while (n % p == 0) n /= p;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

* Calcular el Euler totient para todos los numeros menores o iguales a MX con Sieve of Eratosthenes.

const int MX = 1e6;
bool marked[MX+1];
int phi[MX+1];
/// O(MX log(log(MX)))
void sieve() {
    iota(phi, phi+MX+1, 0);
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MX; i++) {
        if (marked[i]) continue;
        for (int j = i; j <= MX ; j += i) {
            phi[j] -= phi[j] / i;
            marked[j] = true;
        }
        marked[i] = false;
    }
}