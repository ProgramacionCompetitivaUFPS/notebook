Estructura para realizar operaciones de multiplicación y exponenciación modular sobre matrices.

#define MOD 1000000009
const int N = 2; //Maximo size de la matriz

struct matrix {
    int m[N][N], r, c;

    matrix(int _r = N, int _c = N, bool iden = false) {
        r = _r; c = _c;
        memset(m, 0, sizeof(m));
        if (iden) while (_c--) m[_c][_c] = 1;
    }

    matrix operator * (const matrix &B) {
        matrix C(r, B.c);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < B.c; j++)
                for(int k = 0; k < c; k++)
                    C.m[i][j] = (1ll*C.m[i][j] + 1ll*m[i][k]*B.m[k][j]) % MOD;
        return C;
    }
};

matrix pow(matrix A, ll e) {
    matrix ANS(A.r, A.c, true);
    while (e) {
        if (e&1) ANS = ANS * A;
        A = A * A;
        e >>= 1;
    }
    return ANS;
}
