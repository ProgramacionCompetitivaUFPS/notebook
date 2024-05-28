> 🚨 Usar indexando desde 1 en vez de 0. Permite procesar consultas de suma en rangos y actualizaciones puntuales sobre un arreglo.

const int N = 1e5;
int bit[N+1];

void add(int k, int val) {
    for (; k <= N; k += k&-k) bit[k] += val;
}

int rsq(int k) {
    int sum = 0;
    for (; k >= 1; k -= k&-k) sum += bit[k];
    return sum;
}

int rsq(int i, int j) { return rsq(j) - rsq(i-1); }
// Ultimo valor <= o < a val
int lower_find(int val) {
    int id = 0;
    for (int i = 31-__builtin_clz(N); i >= 0; --i) {
        int nid = id | (1<<i);
        if (nid <= N && bit[nid] <= val) { // o bit[nid] < val
            val -= bit[nid];
            id = nid;
        }
    }
    return id;
}
