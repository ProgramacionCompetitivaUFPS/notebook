Calcula el n-ésimo termino de una recurrencia lineal (que depende de los k terminos anteriores).
* Si no es necesario inicializar las matrices multiples veces llamar init(k) en el main una única vez.
Este ejemplo calcula el fibonacci de n como la suma de los k terminos anteriores de la secuencia (En la secuencia común k = 2).
Agregar Matrix Multiplication.

matrix F, T;

void init(int k) {
    F = {k, 1}; // primeros k terminos
    for (int i = 0; i < k; i++)
        F.m[i][0] = i < 2 ? 1 : (F.m[i-1][0]<<1);
    T = {k, k}; // fila k-1 = coeficientes: [c_k, c_k-1, ..., c_1]
    for (int i = 0; i < k-1; i++) T.m[i][i+1] = 1;
    for (int i = 0; i < k; i++) T.m[k-1][i] = 1;
}
/// O(k^3 log(n))
int fib(ll n, int k = 2) {
    init(k);
    matrix ANS = pow(T, n) * F;
    return ANS.m[0][0];
}
