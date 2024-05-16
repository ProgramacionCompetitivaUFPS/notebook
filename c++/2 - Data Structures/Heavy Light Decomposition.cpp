Para inicializar llamar build(). Agregar Segment Tree con un constructor vacio, actualizaciones puntuales y declarar el valor neutro de forma global.
Para consultas sobre aristas guardar el valor de cada arista en su nodo hijo y cambiar pos[u] por pos[u]+1 en la linea 54.

typedef int T; //tipo de dato del segtree
const int MX = 1e5+5;
vector<int> g[MX];
int par[MX], dep[MX], sz[MX];
int pos[MX], top[MX], value[MX];
vector<T> arr;
int idx;

int pre(int u, int p, int d) {
    par[u] = p; dep[u] = d;
    int aux = 1;
    for (auto &v : g[u]) {
        if (v != p) {
            aux += pre(v, u, d+1);
            if (sz[v] >= sz[g[u][0]]) swap(v, g[u][0]);
        }
    }
    return sz[u] = aux;
}

void hld(int u, int p, int t) {
    arr[idx] = value[u]; //vector para inicializar el segtree
    pos[u] = idx++;
    top[u] = t < 0 ? t = u : t;
    for (auto &v : g[u]) {
        if (v != p) {
            hld(v, u, t);
            t = -1;
        }
    }
}

segtree sgt;

void build(int n, int root) {
    idx = 0;
    arr.resize(n);
    pre(root, root, 0);
    hld(root, root, -1);
    sgt = segtree(arr);
}

T query(int u, int v) {
    T ans = neutro;
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) swap(u, v);
        ans = min(ans, sgt.query(pos[top[v]], pos[v]));
        v = par[top[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ans = min(ans, sgt.query(pos[u], pos[v]));
    return ans;
}

void upd(int u, T val) {
    sgt.upd(pos[u], val);
}