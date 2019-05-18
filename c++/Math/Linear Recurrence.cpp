Calcula el fibonacci de n como la suma de los k terminos anteriores de la secuencia (En la secuencia común k = 2).
IMPORTANTE: Debe agregarse Matrix Multiplication.

int fib(long long n, int k = 2) {
    matrix F(k, 1);
    F.m[0][0] = F.m[1][0] = 1;
    for (int i = 2; i < k; i++)
        F.m[i][0] = F.m[i-1][0] * 2;
    matrix T(k, k);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            if (i == k-1 || i == j-1) T.m[i][j] = 1;
    F = pow(T, n) * F;
    return F.m[0][0];
}
