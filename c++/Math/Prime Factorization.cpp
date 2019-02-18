Guarda en factors la lista de factores primos de n de menor a mayor. IMPORTANTE: Debe ejecutarse primero Sieve of Eratosthenes (al menos hasta un numero mayor a la raiz cuadrada de n).

vector<int> factors;

void primeFactors(int n) {
    factors.clear();
    for (int i = 0, p = primes[i]; p*p <= n; p = primes[++i]) {
        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
    }
    if (n > 1) factors.push_back(n);
}
