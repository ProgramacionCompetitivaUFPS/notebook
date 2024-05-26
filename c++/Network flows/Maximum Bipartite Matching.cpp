Halla el maximo match en un grafo bipartito O(|E|*|V|)

struct mbm {
    int l, r;
    vector<vector<int>> g;
    vector<int> match, vis;

    mbm(int l, int r) : l(l), r(r), g(l) {}

    void add_edge(int l, int r) {
        g[l].pb(r);
    }

    bool dfs(int u) {
        for (auto &v : g[u]) {
            if (vis[v]++) continue;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int max_matching() {
        int ans = 0;
        match.assign(r, -1);
        for (int u = 0; u < l; ++u) {
            vis.assign(r, 0);
            ans += dfs(u);
        }
        return ans;
    }
};

Hopcroft Karp: O(E * sqrt(V))

const int INF = INT_MAX;

struct mbm {
    vector<vector<int>> g;
    vector<int> d, match;
    int nil, l, r;
    // u -> 0 to l, v -> 0 to r
    mbm(int l, int r) : l(l), r(r), nil(l+r), g(l+r),
        d(1+l+r, INF), match(l+r, l+r) {}

    void add_edge(int a, int b) {
        g[a].pb(l+b);
        g[l+b].pb(a);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 0; u < l; u++) {
            if (match[u] == nil) {
                d[u] = 0;
                q.push(u);
            } else {
                d[u] = INF;
            }
        }
        d[nil] = INF;
        while (q.size()) {
            int u = q.front(); q.pop();
            if (u == nil) continue;
            for (auto v : g[u]) {
                if (d[match[v]] == INF) {
                    d[match[v]] = d[u]+1;
                    q.push(match[v]);
                }
            }
        }
        return d[nil] != INF;
    }

    bool dfs(int u) {
        if (u == nil) return true;
        for (int v : g[u]) {
            if (d[match[v]] == d[u]+1 && dfs(match[v])) {
                match[v] = u; match[u] = v;
                return true;
            }
        }
        d[u] = INF;
        return false;
    }

    int max_matching() {
        int ans = 0;
        while (bfs()) {
            for (int u = 0; u < l; u++) {
                ans += (match[u] == nil && dfs(u));
            }
        }
        return ans;
    }
};
