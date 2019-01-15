Guarda en primes los números primos menores a MAX.
isPrime() retorna si p es o no un número primo.

const int MAX = 1000000;
vector<int> primes;
bitset<MAX/2> marked;

void sieve() {
	marked[0] = 1;
	primes.push_back(2);
	for (long long i = 3; i < MAX; i += 2) if (!marked[i/2]) {
		primes.push_back(i);
		for (long long j = i*i; j < MAX; j += i*2) marked[j/2] = 1;
	}
}

bool isPrime(int p) {
	if (p%2) return !marked[p/2];
	return p == 2;
}
