La función mu de Mobius devuelve 0 si n es divisible por algún cuadrado.
Si n es libre de cuadrados entonces devuelve 1 o -1 si n tiene un número par o impar de factores primos distintos.
* Calcular Mobius para todos los numeros menores o iguales a MAX con Sieve of Eratosthenes.

static final int MAX = 1000000;
static short mu[] = new short [MAX+1];

///  O(MAX log(log(MAX)))
static void mobius() {
	mu[0] = 0; mu[1] = 1; 
    for (int i = 1; i <= MAX; i++) if (mu[i]==1) {
        for (int j = i+i; j <= MAX; j += i) {
            mu[j] -= mu[i];
        }
    }
}
