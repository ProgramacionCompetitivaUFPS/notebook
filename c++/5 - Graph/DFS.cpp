Búsqueda en profundidad sobre grafos. Recibe un nodo inicial u y visita todos los nodos alcanzables desde u.
DFS puede ser usado para contar la cantidad de componentes conexas en un grafo y puede ser modificado para que retorne información de los nodos dependiendo del problema.

const int MAX = 100005; //Cantidad maxima de nodos
vector<int> g[MAX]; //Lista de adyacencia
bitset<MAX> vis; //Marca los nodos ya visitados
int N, M; //Cantidad de nodos y aristas

void dfs(int u) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

void init() {
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        vis[i] = false;
    }
}
