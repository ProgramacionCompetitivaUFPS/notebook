Dado un valor n retorna el número de enteros positivos menores o iguales a n que son coprimos con n (Coprimos: MCD=1). IMPORTANTE: Debe ejecutarse primero la criba de Eratostenes. La criba debe existir al menos hasta un numero primo mayor a la raiz cuadrada de n.

long long totient(long long n) {
	long long result = n;
	for (int i = 0, factor; (long long)primes[i] * primes[i] <= n; i++) {
		factor = primes[i];
		if (n % factor == 0) {
			while (n % factor == 0) n /= factor;
			result -= result / factor;
		}
	}
	if (n > 1) result -= result / n;
	return result;
}
