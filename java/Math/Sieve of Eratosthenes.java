Guarda en primes los números primos menores o iguales a MAX.
isPrime() retorna si p es o no un número primo.

static int MAX = 10000000;
static ArrayList<Integer> primes = new ArrayList<Integer>();
static boolean sieve[] = new boolean[MAX/2];
	
static void calculatePrimes() {
	sieve[0] = true;
	primes.add(2);
	int i;
	for (i = 3; i*i <= MAX; i += 2) {
		if (!sieve[i/2]) {
			primes.add(i);
			for (int j = i*i; j <= MAX; j += i*2) {
				sieve[j/2] = true;
			}
		}
	}
	for(; i <= MAX; i += 2) {
		if (!sieve[i/2]) primes.add(i);
	}
}

static boolean isPrime(int p) {
	if (p%2 == 0) return p == 2;
	return !sieve[p/2];
}
