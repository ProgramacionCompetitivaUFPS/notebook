Dado un grafo con pesos, positivos o negativos, halla la ruta de costo minimo entre un nodo inicial u y todos los demas nodos.
Tambien halla ciclos negativos.

const ll inf = 1e18;
const int MX = 1e5+5; // Cantidad maxima de nodos
vector<pii> g[MX]; // Lista de adyacencia, u->[(v, cost)]
vector<ll> dist; // Almacena la distancia a cada nodo
// vector<int> cycle; // Para construir el ciclo negativo
int n, m; // Cantidad de nodos y aristas

// O(n*m)
void bellmanFord(int src) {
    dist.assign(n, inf);
    dist[src] = 0;
    for (int i = 0; i < n-1; i++) 
        for (int u = 0; u < n; u++) 
            if (dist[u] != inf) 
                for (auto &v : g[u]) {
                    dist[v.F] = min(dist[v.F], dist[u] + v.S);
                }
    // Encontrar ciclos negativos
    // cycle.clear();
    for (int u = 0; u < n; u++) 
        if (dist[u] != inf) 
            for (auto &v : g[u]) 
                if (dist[v.F] > dist[u] + v.S) { // Ciclo negativo
                    dist[v.F] = -inf;
                    // cycle.pb(v.F); // Para reconstruir
                }
}

void init() {
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
