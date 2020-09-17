Dado un grafo con pesos no negativos halla la ruta de costo mínimo entre un nodo inicial u y todos los demás nodos.

struct edge {
    int v; ll w;
    
    bool operator < (const edge &o) const {
        return o.w < w; //invertidos para que la pq ordene de < a >
    }
};

const ll inf = 1e18;
const int MX = 1e5+5; //Cantidad maxima de nodos
vector<edge> g[MX]; //Lista de adyacencia
bool vis[MX]; //Marca los nodos ya visitados
int pre[MX]; //Almacena el nodo anterior para construir las rutas
ll dist[MX]; //Almacena la distancia a cada nodo
int N, M; //Cantidad de nodos y aristas

void dijkstra(int u) {
    priority_queue<edge> pq;
    pq.push({u, 0});
    dist[u] = 0;
    
    while (pq.size()) {
        u = pq.top().v; pq.pop();
        if (!vis[u]) {
            vis[u] = true;
            for (auto &ed : g[u]) {
                int v = ed.v;
                if (!vis[v] && dist[v] > dist[u] + ed.w) {
                    dist[v] = dist[u] + ed.w;
                    pre[v] = u;
                    pq.push({v, dist[v]});
                }
            }
        }
    }
}

void init() {
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        dist[i] = inf;
        vis[i] = false;
    }
}