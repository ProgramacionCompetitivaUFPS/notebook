Permite hashear árboles para comparar su estructura rápidamente.
Agregar Random Integer para ll

map<ll, ll> table;

ll get(ll x) {
    if (table.count(x)) return table[x];
    return table[x] = rand(0, 1e18);
}

ll hashes[N], sum[N];

void dfs(int u, int p) {
    sum[u] = 0;
    for (auto &v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        sum[u] += hashes[v];
    }
    hashes[u] = get(sum[u]);
}
