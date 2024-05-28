> Permite mantener una colección de conjuntos disyuntos. find(u) indica a qué conjunto pertenece u. unite(u, v) une los conjuntos de u y v en uno.

struct dsu {
    vector<int> par, sz;
    int size; // Cantidad de conjuntos

    dsu(int n) : par(n), sz(n, 1) {
        size = n;
        iota(par.begin(), par.end(), 0);
    }
    // Busca el nodo representativo del conjunto de u
    int find(int u) {
        return par[u] == u ? u : (par[u] = find(par[u]));
    }
    // Une los conjuntos de u y v
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        size--;
    }
    // Cantidad de elementos en el conjunto de u
    int count(int u) { return sz[find(u)]; }
};
