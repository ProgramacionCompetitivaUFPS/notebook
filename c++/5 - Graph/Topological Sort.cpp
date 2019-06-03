Dado un grafo acíclico dirigido (DAG), ordena los nodos linealmente de tal manera que si existe una arista entre los nodos u y v entonces u aparece antes que v.
Este ordenamiento es una manera de poner todos los nodos en una línea recta de tal manera que las aristas vayan de izquierda a derecha.

const int MAX = 100005; //Cantidad maxima de nodos
vector<int> g[MAX]; //Lista de adyacencia
bitset<MAX> vis; //Marca los nodos ya visitados
deque<int> topoSort; //Orden topologico del grafo
int N, M; //Cantidad de nodos y aristas

void dfs(int u) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]) dfs(v);
    }
    topoSort.push_front(u);
}

void init() {
    topoSort.clear();
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        vis[i] = false;
    }
}
