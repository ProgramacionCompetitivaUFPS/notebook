const int MAX_N = 100;
const int MAX_M = 100;
const int KN = log2(MAX_N)+1;
const int KM = log2(MAX_M)+1;
int table[KN][MAX_N][KM][MAX_M];
int _log2N[MAX_N+1];
int _log2M[MAX_M+1];

int MAT[MAX_N][MAX_M];
int n, m, ic, ir, jc, jr;

void calc_log2() {
    _log2N[1] = 0;
    _log2M[1] = 0;
    for (int i = 2; i <= MAX_N; i++) _log2N[i] = _log2N[i/2] + 1;
    for (int i = 2; i <= MAX_M; i++) _log2M[i] = _log2M[i/2] + 1;
}

void build() {
    for (ir = 0; ir < n; ir++) {
        for (ic = 0; ic < m; ic++) 
            table[0][ir][0][ic] = MAT[ir][ic];
        for (jc = 1; jc < KM; jc++) 
            for (ic = 0; ic + (1 <<(jc-1)) < m; ic++) 
                table[0][ir][jc][ic] = min(table[0][ir][jc-1][ic], table[0][ir][jc-1][ic + (1 << (jc-1))]);
    }

    for (jr = 1; jr < KN; jr++) 
        for (ir = 0; ir < n; ir++) 
            for (jc = 0; jc < KM; jc++) 
                for (ic = 0; ic < m; ic++) 
                    table[jr][ir][jc][ic] = min(table[jr-1][ir][jc][ic], table[jr-1][ir+(1<<(jr-1))][jc][ic]);
}

int rmq(int x1, int y1, int x2, int y2) {
    int lenx = x2-x1+1;
    int kx = _log2N[lenx];
    int leny = y2-y1+1;
    int ky = _log2M[leny];

    int min_R1 = min(table[kx][x1][ky][y1], table[kx][x1][ky][y2 + 1 - (1<<ky)]);
    int min_R2 = min(table[kx][x2+1-(1<<kx)][ky][y1], table[kx][x2+1- (1<<kx)][ky][y2 + 1 - (1<<ky)]);
    return min(min_R1, min_R2);
}
