Modificación del BFS para detectar si un grafo es bipartito.

const int MAX = 100005; //Cantidad maxima de nodos
vector<int> g[MAX]; //Lista de adyacencia
int color[MAX]; //Almacena el color de cada nodo
bool bipartite; //true si el grafo es bipartito
int N, M; //Cantidad de nodos y aristas

void bfs(int u) {
    queue<int> q;
    q.push(u);
    color[u] = 0;
    
    while (q.size()) {
        u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (color[v] == -1) {
                color[v] = color[u]^1;
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
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        color[i] = -1;
    }
}
