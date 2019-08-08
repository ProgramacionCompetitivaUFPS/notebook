* Calcula la suma de los divisores de n. Agregar Prime Factorization y Modular Exponentiation (sin el modulo).

ll sumDiv(ll n) {
    map<ll, int> f;
    fact(n, f);
    ll ans = 1;
    for (auto p : f) {
        ans *= (exp(p.first, p.second+1)-1)/(p.first-1);
    }
    return ans;
}

* Calcula la cantidad de divisores de n. Agregar Prime Factorization.

ll cantDiv(ll n) {
    map<ll, int> f;
	fact(n, f);
    ll ans = 1;
    for (auto p : f) ans *= (p.second + 1);
    return ans;
}

* Calcular la cantidad de divisores para todos los numeros menores o iguales a MAX con Sieve of Eratosthenes.

const int MAX = 1000000;
int cnt[MAX+1];
bitset<MAX+1> marked;

void sieve() {
    fill(cnt, cnt+MAX+1, 1);
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MAX; i++) if (!marked[i]) {
        cnt[i]++;
        for (int j = i*2; j <= MAX ; j += i) {
            int n = j, c = 1;
            while (n%i == 0) n /= i, c++;
            cnt[j] *= c;
            marked[j] = true;
        }
    }
}
