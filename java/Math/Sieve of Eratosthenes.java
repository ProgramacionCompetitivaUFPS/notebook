Guarda en primes los números primos menores a MAX

import java.util.ArrayList;

static int MAX = 10000000;
static ArrayList<Integer> primes = new ArrayList<Integer>();
static boolean sieve[] = new boolean[MAX+5];
	
static void calculatePrimes() {
  sieve[0] = sieve[1] = true;
  int i;
  for (i = 2; i * i <= MAX; ++i) {
    if (!sieve[i]) {
      primes.add(i);
      for (int j = i * i; j <= MAX; j += i)
        sieve[j] = true;
    }
  }
  for(; i <= MAX; i++){
  	if (!sieve[i]) {
      primes.add(i);
    }
  }
}
