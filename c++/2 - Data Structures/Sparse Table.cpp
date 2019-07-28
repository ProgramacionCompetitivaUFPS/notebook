Estructura de datos que permite procesar consultas por rangos.

const int MAX = 1000;
const int LOG = log2(MAX_N)+1;
int spt[LOG][MAX];
int _log2[MAX+1];
int arr[MAX];
int N;

void calc_log2() {
    _log2[1] = 0;
    for (int i = 2; i <= MAX; i++) _log2[i] = _log2[i/2]+1;
}

void build() {
    for (int i = 0; i < N; i++) spt[0][i] = arr[i];
    for (int j = 0; j < LOG-1; j++) {
        for (int i = 0; i+(1<<(j+1)) <= N; i++) {
            spt[j+1][i] = min(spt[j][i], spt[j][i+(1<<j)]);
}

int rmq(int i, int j) {
    int k = _log2[j-i+1];
    return min(spt[k][i], spt[k][j-(1<<k)+1]);
}
