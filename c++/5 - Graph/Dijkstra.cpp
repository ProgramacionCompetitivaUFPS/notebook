Dado un grafo con pesos no negativos halla la ruta de costo mínimo entre un nodo inicial u y todos los demás nodos.

struct Edge {
	int v;
	long long w;
	
	bool operator < (const Edge &b) const {
		return w > b.w; //Orden invertido
	}
};

const int MAX = 100005; //Cantidad maxima de nodos
vector<Edge> g[MAX]; //Lista de adyacencia
bitset<MAX> vis; //Marca los nodos ya visitados
long long dist[MAX]; //Almacena la distancia a cada nodo
int par[MAX]; //Almacena el nodo anterior para construir las rutas
int n, m; //Cantidad de nodos y aristas

void dijkstra(int u) {
	priority_queue<Edge> pq;
	pq.push({u, 0});
	dist[u] = 0;
	
	while (pq.size()) {
		u = pq.top().v;
		pq.pop();
		if (!vis[u]) {
			vis[u] = true;
			for (auto nx : g[u]) {
				int v = nx.v;
				if(!vis[v] && dist[v] > dist[u] + nx.w) {
					dist[v] = dist[u] + nx.w;
					par[v] = u;
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

void init() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        dist[i] = 1ll << 62;
        vis[i] = false;
    }
}
