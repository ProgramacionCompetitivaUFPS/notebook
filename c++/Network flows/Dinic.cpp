Halla el flujo máximo O(E * V ^ 2)

struct edge { int v, cap, inv, flow; };

struct network {
    int n, s, t;
    vector<int> lvl;
    vector<vector<edge>> g;

    network(int n) : n(n), lvl(n), g(n) {}

    void add_edge(int u, int v, int c) {
        g[u].pb({v, c, (int)g[v].size(), 0});
        g[v].pb({u, 0, (int)g[u].size()-1, c});
    }

    bool bfs() {
        fill(lvl.begin(), lvl.end(), -1);
        queue<int> q;
        lvl[s] = 0;
        for (q.push(s); q.size(); q.pop()) {
            int u = q.front();
            for (auto &e : g[u]) {
                if (e.cap > 0 && lvl[e.v] == -1) {
                    lvl[e.v] = lvl[u]+1;
                    q.push(e.v);
                }
            }
        }
        return lvl[t] != -1;
    }

    int dfs(int u, int nf) {
        if (u == t) return nf;
        int res = 0;
        for (auto &e : g[u]) {
            if (e.cap > 0 && lvl[e.v] == lvl[u]+1) {
                int tf = dfs(e.v, min(nf, e.cap));
                res += tf; nf -= tf; e.cap -= tf;
                g[e.v][e.inv].cap += tf;
                g[e.v][e.inv].flow -= tf;
                e.flow += tf;
                if (nf == 0) return res;
            }
        }
        if (!res) lvl[u] = -1;
        return res;
    }

    int max_flow(int so, int si, int res = 0) {
        s = so; t = si;
        while (bfs()) res += dfs(s, INT_MAX);
        return res;
    }
};
