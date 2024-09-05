> Util para responder queries del tipo "cuantos vertices en el subárbol de u cumplen con x propiedad" en O(nlogn * k) para todas las queries.
> Esta implementación permite mantener una única estructura global agregando y quitando información. k es el costo de actualizar esa estructura global.
> Problema de ejemplo: dado un árbol con los nodos coloreados, las consultas son: cuántos nodos del subárbol de u tienen color igual a c.

const int N = 1e5+5;
vector<int> g[N];
int sz[N], big[N]; // big[u] = el hijo de u con mayor tamaño
int col[N]; // Del problema de ejemplo
int cnt[N]; // Estructura global del ejemplo

int pre(int u, int p) {
    sz[u] = 1; big[u] = -1;
    int mx = 0;
    for (auto &v : g[u]) {
        if (v != p) {
            sz[u] += pre(v, u);
            if (sz[v] > mx) mx = sz[v], big[u] = v;
        }
    }
    return sz[u];
}

void upd(int u, int p, int x) {
    cnt[col[u]] += x; // En el problema de ejemplo k = O(1)
    for (auto &v : g[u]) 
        if (v != p && v != big[u]) 
            upd(v, u, x);
}

void dfs(int u, int p, bool keep) {
    for (auto &v : g[u]) 
        if (v != p && v != big[u]) 
            dfs(v, u, false);
    if (big[u] != -1) dfs(big[u], u, true);
    // Agregar información del subárbol de los hijos de u != a big[u]
    upd(u, p, 1);
    // Aqui se responderían las queries
    // cnt[c] = cantidad de nodos del subárbol de u con color c
    big[u] = -1;
    if (!keep) upd(u, p, -1);  // Quitar información del subárbol de u
}
