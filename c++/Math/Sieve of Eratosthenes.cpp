Guarda en primes los números primos menores o iguales a MAX

#include <vector>

const int MAX = 10000000;
vector<int> primes;
bool sieve[MAX+5];

void calculatePrimes() {
  sieve[0] = sieve[1] = 1;
  int i;
  for (i = 2; i * i <= MAX; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= MAX; j += i) sieve[j] = true;
    }
  }
  for(;i <= MAX; i++){
  	if (!sieve[i]) {
      primes.push_back(i);
  	}
  }
}
