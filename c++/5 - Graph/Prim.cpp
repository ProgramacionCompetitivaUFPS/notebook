Dado un grafo halla el costo total de su arbol cobertor mínimo.

struct edge {
    int v;
    long long w;
    
    bool operator < (const edge &b) const {
        return w > b.w; //Orden invertido
    }
};

const int MAX = 100005; //Cantidad maxima de nodos
vector<edge> g[MAX]; //Lista de adyacencia
bitset<MAX> vis; //Marca los nodos ya visitados
long long ans; //Costo total del arbol cobertor minimo
int N, M; //Cantidad de nodos y aristas

void prim() {
    priority_queue<edge> pq;
    vis[0] = true;
    for (auto &ed : g[0]) {
        int v = ed.v;
        if (!vis[v]) pq.push({v, ed.w});
    }
    
    while (pq.size()) {
        edge ed = pq.top(); pq.pop(); 
        int u = ed.v;
        if (!vis[u]) {
            ans += ed.w;
            vis[u] = true;
            for (auto &e : g[u]) {
                int v = e.v;
                if (!vis[v]) pq.push({v, e.w});
            }
        }
    }
}

void init() {
    ans = 0;
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        vis[i] = false;
    }
}
