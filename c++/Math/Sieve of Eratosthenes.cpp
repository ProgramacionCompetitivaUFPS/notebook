Guarda en primes los números primos menores o iguales a MAX. Para saber si p es un número primo, hacer: if (!marked[p])

const int MAX = 1000000;
const int SQRT = 1000;
vector<int> primes;
bitset<MAX+1> marked;

void sieve() {
    marked[1] = 1;
    int i = 2;
    for (; i <= SQRT; i++) if (!marked[i]) {
        primes.push_back(i);
        for (int j = i*i; j <= MAX; j += i<<1) marked[j] = 1;
    }
    for (; i <= MAX; i++) if (!marked[i]) primes.push_back(i);
}
