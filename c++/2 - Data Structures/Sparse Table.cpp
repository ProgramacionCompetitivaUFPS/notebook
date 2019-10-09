Estructura de datos que permite procesar consultas por rangos.

const int MAX = 10001;
const int LOG = log2(MAX)+1;
int spt[LOG][MAX];
int arr[MAX];
int N;

void build() {
    for (int i = 0; i < N; i++) spt[0][i] = arr[i];
    for (int j = 0; j < LOG-1; j++)
        for (int i = 0; i+(1<<(j+1)) <= N; i++)
            spt[j+1][i] = min(spt[j][i], spt[j][i+(1<<j)]);
}

int rmq(int i, int j) {
    int k = 31-__builtin_clz(j-i+1);
    return min(spt[k][i], spt[k][j-(1<<k)+1]);
}
