Modificacion del BFS para detectar si un grafo es bipartito.

const int MX = 1e5+5; // Cantidad maxima de nodos
vector<int> g[MX]; // Lista de adyacencia
vector<int> color; // Almacena el color de cada nodo
bool bipartite; // true si el grafo es bipartito
int n, m; // Cantidad de nodos y aristas

void bfs(int u) {
    queue<int> q;
    q.push(u);
    color[u] = 0;

    while (q.size()) {
        u = q.front();
        q.pop();
        for (auto &v : g[u]) {
            if (color[v] == -1) {
                color[v] = 1-color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                bipartite = false;
                return;
            }
        }
    }
}

void init() {
    bipartite = true;
    color.assign(n, -1);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
