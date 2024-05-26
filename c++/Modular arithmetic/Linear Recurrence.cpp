Calcula el n-esimo termino de una recurrencia lineal (que depende de los k terminos anteriores).
* Llamar init(k) en el main una unica vez si no es necesario inicializar las matrices multiples veces.
Este ejemplo calcula el fibonacci de n como la suma de los k terminos anteriores de la secuencia (En la secuencia comun k es 2).
Agregar Matrix Multiplication con un construcctor vacio.

matrix F, T;

void init(int k) {
    F = {k, 1}; // primeros k terminos
    F[k-1][0] = 1;
    T = {k, k}; // fila k-1 = coeficientes: [c_k, c_k-1, ..., c_1]
    for (int i = 0; i < k-1; i++) T[i][i+1] = 1;
    for (int i = 0; i < k; i++) T[k-1][i] = 1;
}
// O(k^3 log(n))
int fib(ll n, int k = 2) {
    init(k);
    matrix ans = pow(T, n+k-1) * F;
    return ans[0][0];
}
