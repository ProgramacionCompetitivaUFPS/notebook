Estructura de datos que permite procesar consultas por rangos y actualizaciones individuales sobre un arreglo.

const int MX = 1e5;
int bit[MX+1];

void add(int k, int val) {
    for (; k <= MX; k += k&-k) bit[k] += val;
}

int rsq(int k) {
    int sum = 0;
    for (; k >= 1; k -= k&-k) sum += bit[k];
    return sum;
}

int rsq(int i, int j) { return rsq(j) - rsq(i-1); }

int lower_find(int val) { /// last value < or <= to val
    int id = 0;
    for (int i = 31-__builtin_clz(MX); i >= 0; --i) {
        int nid = id | (1<<i);
        if (nid <= MX && bit[nid] <= val) { /// change <= to <
            val -= bit[nid];
            id = nid;
        }
    }
    return idx;
}