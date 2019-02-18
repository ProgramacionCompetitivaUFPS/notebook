Dado un valor n retorna el número de enteros positivos menores o iguales a n que son coprimos con n (Coprimos: MCD=1). IMPORTANTE: Debe ejecutarse primero Sieve of Eratosthenes (al menos hasta un numero mayor a la raiz cuadrada de n).

long long totient(long long n) {
    long long tot = n;
    for (int i = 0, p = primes[i]; p*p <= n; p = primes[++i]) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            tot -= tot / p;
        }
    }
    if (n > 1) tot -= tot / n;
    return tot;
}
