const int MX = 1e5+5;
vector<int> g[MX];
int par[MX], dep[MX], sz[MX];

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

void build(int u, int p = -1, int d = 1) {
    int k = pre(u, p);
    int c = centroid(u, p, k/2);
    par[c] = p; dep[c] = d;
    // dfs(c, p, ...);
    for (auto &v : g[c]) 
        if (!dep[v]) build(v, c, d+1);
}

int lca(int u, int v) {
    for (; u != v; u = par[u]) 
        if (dep[v] > dep[u]) swap(u, v);
    return u;
}