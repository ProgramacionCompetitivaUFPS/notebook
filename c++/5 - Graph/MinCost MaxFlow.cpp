Dado un grafo, halla el flujo maximo y el costo minimo entre el source s y el sink t.

struct edge {
    int u, v, cap, flow, cost;
    int rem() { return cap - flow; }
};

const int inf = 1e9;
const int MX = 405; //Cantidad maxima TOTAL de nodos
vector<int> g[MX]; //Lista de adyacencia
vector<edge> e; //Lista de aristas
vector<bool> in_queue; //Marca los nodos que estan en cola
vector<int> pre, dist, cap; //Almacena el nodo anterior, la distancia y el flujo de cada nodo
int mxflow, mncost; //Flujo maximo y costo minimo
int N; //Cantidad TOTAL de nodos

void add_edge(int u, int v, int cap, int cost) {
    g[u].push_back(e.size());
    e.push_back({u, v, cap, 0, cost});
    g[v].push_back(e.size());
    e.push_back({v, u, 0, 0, -cost});
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