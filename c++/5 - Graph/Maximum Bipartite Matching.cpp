/// O(|E|*|V|)
struct mbm {
    int l, r;
    vector<vector<int>> g;
    vector<int> match, vis;
    
    mbm(int l, int r) : l(l), r(r), g(l) {}
    
    void add_edge(int l, int r) { g[l].push_back(r); }
    
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