La función mu de Mobius devuelve 0 si n es divisible por algún cuadrado.
Si n es libre de cuadrados entonces devuelve 1 o -1 si n tiene un número par o impar de factores primos distintos.
* Calcular Mobius para todos los numeros menores o iguales a MAX con Sieve of Eratosthenes.

const int MAX = 1000000;
short mu[MAX+1] = {0, 1};
///  O(MAX log(log(MAX)))
void mobius() {
    for (int i = 1; i <= MAX; i++) if (mu[i]) {
        for (int j = i+i; j <= MAX; j += i) {
            mu[j] -= mu[i];
        }
    }
}
