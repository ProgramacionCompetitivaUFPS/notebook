Dado un grafo, halla el flujo maximo y el costo minimo entre el source s y el sink t.

struct edge {
    int u, v, cap, flow, cost;
    int rem() { return cap - flow; }
};

const int inf = 1e9;
const int MX = 405; // Cantidad maxima TOTAL de nodos
vector<int> g[MX]; // Lista de adyacencia
vector<edge> e; // Lista de aristas
vector<bool> in_queue; // Marca los nodos que estan en cola
vector<int> pre, dist, cap; // Almacena el nodo anterior, la distancia y el flujo de cada nodo
int mxflow, mncost; // Flujo maximo y costo minimo
int N; // Cantidad TOTAL de nodos

void add_edge(int u, int v, int cap, int cost) {
    g[u].pb(e.size());
    e.pb({u, v, cap, 0, cost});
    g[v].pb(e.size());
    e.pb({v, u, 0, 0, -cost});
}

void flow(int s, int t) {
    mxflow = mncost = 0;
    in_queue.assign(N, false);
    while (true) {
        dist.assign(N, inf); dist[s] = 0;
        cap.assign(N, 0); cap[s] = inf;
        pre.assign(N, -1); pre[s] = 0;
        queue<int> q; q.push(s);
        in_queue[s] = true;

        while (q.size()) {
            int u = q.front(); q.pop();
            in_queue[u] = false;
            for (int &id : g[u]) {
                edge &ed = e[id];
                int v = ed.v;
                if (ed.rem() && dist[v] > dist[u]+ed.cost) {
                    dist[v] = dist[u]+ed.cost;
                    cap[v] = min(cap[u], ed.rem());
                    pre[v] = id;
                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = true;
                    }
                }
            }
        }
        if (pre[t] == -1) break;
        mxflow += cap[t];
        mncost += cap[t] * dist[t];
        for (int v = t; v != s; v = e[pre[v]].u) {
            e[pre[v]].flow += cap[t];
            e[pre[v]^1].flow -= cap[t];
        }
    }
}

void init() {
    e.clear();
    for (int i = 0; i <= N; i++) {
        g[i].clear();
    }
}

// O(V * E * 2 * log(E))
template <class type>
struct mcmf {
    struct edge { int u, v, cap, flow; type cost; };

    int n;
    vector<edge> ed;
    vector<vector<int>> g;
    vector<int> p;
    vector<type> d, phi;

    mcmf(int n) : n(n), g(n), p(n), d(n), phi(n) {}

    void add_edge(int u, int v, int cap, type cost) {
        g[u].pb(ed.size());
        ed.pb({u, v, cap, 0, cost});
        g[v].pb(ed.size());
        ed.pb({v, u, 0, 0, -cost});
    }

    bool dijkstra(int s, int t) {
        fill(d.begin(), d.end(), INF);
        fill(p.begin(), p.end(), -1);
        set<pair<type, int>> q;
        d[s] = 0;
        for (q.insert({d[s], s}); q.size();) {
            int u = (*q.begin()).second; q.erase(q.begin());
            for (auto v : g[u]) {
                auto &e = ed[v];
                type nd = d[e.u]+e.cost+phi[e.u]-phi[e.v];
                if (0 < (e.cap-e.flow) && nd < d[e.v]) {
                    q.erase({d[e.v], e.v});
                    d[e.v] = nd; p[e.v] = v;
                    q.insert({d[e.v], e.v});
                }
            }
        }
        for (int i = 0; i < n; i++) phi[i] = min(INF, phi[i]+d[i]);
        return d[t] != INF;
    }

    pair<int, type> max_flow(int s, int t) {
        type mc = 0;
        int mf = 0;
        fill(phi.begin(), phi.end(), 0);
        while (dijkstra(s, t)) {
            int flow = INF;
            for (int v = p[t]; v != -1; v = p[ed[v].u]) 
                flow = min(flow, ed[v].cap-ed[v].flow);
            for (int v = p[t]; v != -1; v = p[ed[v].u]) {
                edge &e1 = ed[v];
                edge &e2 = ed[v^1];
                mc += e1.cost*flow;
                e1.flow += flow;
                e2.flow -= flow;
            }
            mf += flow;
        }
        return {mf, mc};
    }
};
