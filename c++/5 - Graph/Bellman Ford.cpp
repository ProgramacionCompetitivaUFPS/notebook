Dado un grafo con pesos, positivos o negativos, halla la ruta de costo mínimo entre un nodo inicial u y todos los demás nodos.
Tambien halla ciclos negativos.

ll INF = 1e18;

const int MAX = 100005; //Cantidad maxima de nodos
vector<pii> g[MAX]; //Lista de adyacencia, u->[(v, cost)]
ll dist[MAX]; //Almacena la distancia a cada nodo
//vector<int> cycle; //Para construir el ciclo negativo
int N, M; //Cantidad de nodos y aristas

/// O(N*M)
void bellmanFord(int src) {
    fill(dist, dist+N, INF);
    dist[src] = 0;
    for (int i = 0; i < N-1; i++)
        for (int u = 0; u < N; u++)
            if (dist[u] != INF)
                for (auto v : g[u]) {
                    dist[v.F] = min(dist[v.F], dist[u] + v.S);
                }
    //Encontrar ciclos negativos
    for (int u = 0; u < N; u++)
        if (dist[u] != INF)
            for (auto v : g[u])
                if (dist[v.F] > dist[u] + v.S) { //Ciclo negativo
                    dist[v.F] = -INF;
                    //cycle.pb(v.F); //Para reconstruir
                }
}

void init() {
    for(int i = 0; i <= N; i++) {
        g[i].clear();
    }
}
