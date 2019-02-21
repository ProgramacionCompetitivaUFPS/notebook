Calcula el fibonacci de n como la suma de los k terminos anteriores de la secuencia (En la secuencia común k = 2).
IMPORTANTE: Debe agregarse Matrix Multiplication.

int fib(int k, long long n) {
	matrix F(k, 1);
	F.m[0][0] = 1;
	for (int i = 0; i < k-1; i++)
		F.m[i+1][0] = 1 << i;
	matrix T(k, k);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			if (i == k-1 || i == j-1) T.m[i][j] = 1;
	F = F * pow(T, n+k);
	return F.m[0][0];
}
