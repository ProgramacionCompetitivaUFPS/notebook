Guarda en primes los números primos menores o iguales a MAX.
Para saber si p es un número primo, hacer: if (!marked[p])

const int MAX = 1000000;
const int SQRT = 1000;
vector<int> primes;
bitset<MAX+1> marked;

void sieve() {
	marked[1] = 1;
	primes.push_back(2);
	for (int i = 4; i <= MAX; i += 2) marked[i] = 1;
	for (int i = 3; i <= SQRT; i += 2) if (!marked[i]) {
		primes.push_back(i);
		for (int j = i*i; j <= MAX; j += i*2) marked[j] = 1;
	}
}
