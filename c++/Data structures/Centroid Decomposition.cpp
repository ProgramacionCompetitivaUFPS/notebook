// Problema de ejemplo: dado un árbol, las actualizaciones son marcar nodos y las consultas son calcular la distancia mínima entre un nodo u y un nodo marcado.

const int N = 1e5+5;
vector<int> g[N];
int par[N], dep[N], sz[N];
map<int, int> dist[N]; // Distancia entre dos nodos en el árbol original
vector<int> ans; // Respuesta optima de cada centroide hacía su subárbol

int pre(int u, int p) {
    sz[u] = 1;
    for (auto &v : g[u]) 
        if (!dep[v] && v != p) 
            sz[u] += pre(v, u);
    return sz[u];
}

int centroid(int u, int p, int k) {
    for (auto &v : g[u]) 
        if (!dep[v] && v != p && sz[v] > k) 
            return centroid(v, u, k);
    return u;
}
// Calcular información de cada centroide hacía los nodos de su subárbol
void dfs(int u, int p, int c, int d = 0) {
    dist[c][u] = d; // Depende de lo que pida el problema
    for (auto &v : g[u]) {
        if (!dep[v] && v != p) {
            dfs(v, u, c, d+1);
        }
    }
}
// O(nlogn * k) En este ejemplo k = logn por el mapa dist en el dfs
void build(int u, int p = -1, int d = 1) {
    int k = pre(u, p);
    int c = centroid(u, p, k/2);
    par[c] = p; dep[c] = d;
    dfs(c, p, c);
    for (auto &v : g[c]) 
        if (!dep[v]) build(v, c, d+1);
}
// O(logn) lca de u y v en el árbol de centroides
// La ruta de u a v en el árbol original pasa por este lca
int lca(int u, int v) {
    for (; u != v; u = par[u]) 
        if (dep[v] > dep[u]) swap(u, v);
    return u;
}
// O((logn)^2) Actualiza la respuesta de los ancestros de u
void upd(int u) {
    for (int c = u; c != -1; c = par[c]) {
        ans[c] = min(ans[c], dist[c][u]);
    }
}
// O((logn)^2) Combina la respuesta del centroide c + el costo de c a u
int query(int u) {
    int mn = N;
    for (int c = u; c != -1; c = par[c]) {
        mn = min(mn, ans[c] + dist[c][u]);
    }
    return mn;
}
