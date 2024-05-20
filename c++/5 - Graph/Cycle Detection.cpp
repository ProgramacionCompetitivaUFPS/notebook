Determina si un grafo dirigido tiene o no ciclos (si es un DAG o no).

const int MX = 1e5+5; // Cantidad maxima de nodos
vector<int> g[MX]; // Lista de adyacencia
vector<int> vis; // Marca el estado de los nodos ya visitados
bool cycle; // true si el grafo tiene ciclos
int n, m; // Cantidad de nodos y aristas

void dfs(int u) {
    if (cycle) return;
    vis[u] = 1;
    for (auto &v : g[u]) {
        if (!vis[v]) dfs(v);
        else if (vis[v] == 1) {
            cycle = true;
            break;
        }
    }
    vis[u] = 2;
}

void init() {
    vis.assign(n, 0);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
