Estructura para realizar operaciones de multiplicación y exponenciación modular sobre matrices.

static long mod = 1000000007;
static int N = 2; //tamanio maximo de la matriz

static class matrix {
    int m[][] = new int[N][N];
    int r, c;

    matrix(int _r, int _c, boolean iden) {
        r = _r; c = _c;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                m[i][j] = 0;
            }
        }
        if (iden) while (_c-- > 0) m[_c][_c] = 1;
    }

    
    
    matrix mul (matrix B) {
        matrix C = new matrix(r, B.c, false);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < B.c; j++)
                for(int k = 0; k < c; k++)
                    C.m[i][j] = (int)(((1l*C.m[i][j]) + (1l*m[i][k]*B.m[k][j]))% mod);
        return C;
    }
}

static matrix pow(matrix A, long e) {
    if (e == 0) return new matrix(A.r, A.c, true);
    if ((e&1) == 1) return A.mul(pow(A, e-1));
    matrix X = pow(A, e/2);
    return X.mul(X);
}
