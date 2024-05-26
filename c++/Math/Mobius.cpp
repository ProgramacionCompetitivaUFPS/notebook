La funcion mu de Mobius devuelve 0 si n es divisible por algun cuadrado (x^2).
Si n es libre de cuadrados entonces devuelve 1 o -1 si n tiene un numero par o impar de factores primos distintos.
* Calcular Mobius para todos los numeros menores o iguales a MX con Sieve of Eratosthenes.

const int MX = 1e6;
short mu[MX+1] = {0, 1};
// O(MX log(log(MX)))
void mobius() {
    for (int i = 1; i <= MX; i++) {
        if (!mu[i]) continue;
        for (int j = i*2; j <= MX; j += i) {
            mu[j] -= mu[i];
        }
    }
}
