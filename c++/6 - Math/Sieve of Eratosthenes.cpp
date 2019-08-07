Guarda en primes los números primos menores o iguales a MAX. Para saber si p es un número primo, hacer: if (!marked[p]).

const int MAX = 10000000;
bitset<MAX+1> marked;
vector<int> primes;
/// O(MAX log(log(MAX)))
void sieve() {
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MAX; i++) if (!marked[i]) {
        primes.push_back(i);
        for (ll j = 1ll*i*i; j <= MAX; j += i) marked[j] = true;
    }
}
