La función totient de Euler devuelve la cantidad de enteros positivos menores o iguales a n que son coprimos con n (gcd(n, i) = 1)

* Dado un valor n calcula el Euler totient de n. Debe ejecutarse primero Sieve of Eratosthenes (al menos hasta un numero mayor a la raiz cuadrada de n).

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

* Calcular el Euler totient para todos los numeros menores o iguales a MAX.

const int MAX = 100;
int totient[MAX+1]; 
bitset<MAX+1> marked;

void totient() {
    marked[1] = 1;
    for (int i = 0; i <= MAX; i++) totient[i] = i;
    for (int i = 2; i <= MAX; i++) if (!marked[i]) {
        for (int j = i; j <= MAX ; j += i){
            totient[j] -= totient[j] / i;
            marked[j] = 1;
        }
        marked[i] = 0;
    }
}
