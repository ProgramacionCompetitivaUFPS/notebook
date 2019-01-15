Guarda en primes los números primos menores a MAX.
isPrime() retorna si p es o no un número primo.

static int MAX = 1000000;
static ArrayList<Integer> primes = new ArrayList<Integer>();
static boolean marked[] = new boolean[MAX/2];
	
static void sieve() {
	marked[0] = true;
	primes.add(2);
	for (long i = 3; i < MAX; i += 2) if (!marked[i/2]) {
		primes.add(i);
		for (long j = i*i; j < MAX; j += i*2) marked[j/2] = true;
	}
}

static boolean isPrime(int p) {
	if (p%2 != 0) return !sieve[p/2];
	return p == 2;
}
