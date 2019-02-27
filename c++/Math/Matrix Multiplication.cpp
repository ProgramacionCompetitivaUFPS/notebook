Estructura para realizar operaciones de multiplicación y exponenciación modular sobre matrices.

#define mod 1000000007
const int N = 2;

struct matrix {
    int m[N][N], r, c;

    matrix(int _r, int _c) {
        r = _r; c = _c;
        memset(m, 0, sizeof(m));
    }
    
    matrix operator * (matrix B) {
        matrix C(r, B.c);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < B.c; j++)
                for(int k = 0; k < c; k++)
                    C.m[i][j] = (1ll*C.m[i][j] + 1ll*m[i][k]*B.m[k][j]) % mod;
        return C;
    }
};

matrix pow(matrix A, long long e) {
    if (e == 1) return A;
    if (e % 2) return A * pow(A, e-1);
    matrix X = pow(A, e/2);
    return X * X;
}
