Estructura de datos que permite procesar consultas por rangos.

const int MX = 1e5+5;
const int LG = log2(MX)+1;
int spt[LG][MX];
int arr[MX];
int n;

void build() {
    for (int i = 0; i < n; i++) spt[0][i] = arr[i];
    for (int j = 0; j < LG-1; j++)
        for (int i = 0; i+(1<<(j+1)) <= n; i++)
            spt[j+1][i] = min(spt[j][i], spt[j][i+(1<<j)]);
}

int rmq(int i, int j) {
    int k = 31-__builtin_clz(j-i+1);
    return min(spt[k][i], spt[k][j-(1<<k)+1]);
}