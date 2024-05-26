Guarda en primes los numeros primos menores o iguales a MX. Para saber si p es un número primo, hacer: if (!marked[p]).

const int MX = 1e6;
bool marked[MX+1];
vector<int> primes;
// O(MX log(log(MX)))
void sieve() {
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MX; i++) {
        if (marked[i]) continue;
        primes.pb(i);
        for (ll j = 1ll*i*i; j <= MX; j += i) marked[j] = true;
    }
}
