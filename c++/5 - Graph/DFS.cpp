Busqueda en profundidad sobre grafos. Recibe un nodo inicial u y visita todos los nodos alcanzables desde u.
DFS puede ser usado para contar la cantidad de componentes conexas en un grafo y puede ser modificado para que retorne informacion de los nodos dependiendo del problema.

const int MX = 1e5+5; // Cantidad maxima de nodos
vector<int> g[MX]; // Lista de adyacencia
vector<bool> vis; // Marca los nodos ya visitados
int n, m; // Cantidad de nodos y aristas

void dfs(int u) {
    vis[u] = true;
    for (auto &v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

void init() {
    vis.assign(n, false);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
