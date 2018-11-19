Guarda en primes los números primos menores o iguales a MAX.
isPrime() retorna si p es o no un número primo.

const int MAX = 10000000;
vector<int> primes;
bool sieve[MAX/2];

void calculatePrimes() {
	sieve[0] = 1;
	primes.push_back(2);
	int i;
	for (i = 3; i*i <= MAX; i += 2) {
		if (!sieve[i/2]) {
			primes.push_back(i);
			for (int j = i*i; j <= MAX; j += i*2) {
				sieve[j/2] = 1;
			}
		}
	}
	for(; i <= MAX; i += 2) {
		if (!sieve[i/2]) primes.push_back(i);
	}
}

bool isPrime(int p) {
	if (p%2 == 0) return p == 2;
	return !sieve[p/2];
}
