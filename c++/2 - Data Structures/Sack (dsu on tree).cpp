Tecnica basada en disjoint set, util para responer queries sobre arboles del tipo "cuantos vertices en el subarbol de u cumplen con alguna propiedad" en O(n log(n)) para todas las queries.

const int MX = 1e5+5;
vector<int> g[MX];
int sz[MX];
bool big[MX];
int cnt[MX];

void pre(int u, int p) {
    sz[u] = 1;
    for (auto &v : g[u]) {
        if (v != p) {
            pre(v, u);
            sz[u] += sz[v];
        }
    }
}

void upd(int u, int p, int x) {
    cnt[u] += x;
    for (auto &v : g[u])
        if (v != p && !big[v])
            upd(v, u, x);
}

void dfs(int u, int p, bool keep) {
    int mx = -1, id = -1;
    for (auto &v : g[u]) 
        if (v != p && sz[v] > mx) 
            mx = sz[v], id = v;
    for (auto &v : g[u]) 
        if (v != p && v != id) 
            dfs(v, u, false);
    if (id != -1) {
        dfs(id, u, true);
        big[id] = true;
    }
    upd(u, p, 1);
    /*Aqui se responden las queries. cnt[u] es el numero de 
    vertices en el subarbol de u que cumplen la propiedad.*/
    if (id != -1) 
        big[id] = false;
    if (!keep) 
        upd(u, p, -1);
}