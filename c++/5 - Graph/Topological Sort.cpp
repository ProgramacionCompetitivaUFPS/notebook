Dado un grafo aciclico dirigido (DAG), ordena los nodos linealmente de tal manera que si existe una arista entre los nodos u y v entonces u aparece antes que v.
Este ordenamiento es una manera de poner todos los nodos en una linea recta de tal manera que las aristas vayan de izquierda a derecha.

const int MX = 1e5+5; // Cantidad maxima de nodos
vector<int> g[MX]; // Lista de adyacencia
vector<bool> vis; // Marca los nodos ya visitados
deque<int> order; // Orden topologico del grafo
int n, m; // Cantidad de nodos y aristas

void toposort(int u) {
    vis[u] = true;
    for (auto &v : g[u]) {
        if (!vis[v]) toposort(v);
    }
    order.push_front(u);
}

void init() {
    order.clear();
    vis.assign(n, false);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
