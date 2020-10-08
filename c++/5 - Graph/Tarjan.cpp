Dado un grafo dirigido halla las componentes fuertemente conexas (SCC).

const int MX = 1e5+5; //Cantidad maxima de nodos
vector<int> g[MX]; //Lista de adyacencia
bool vis[MX]; //Marca nodos visitados para construir la scc
stack<int> st;
int low[MX], num[MX], cont;
int comp[MX]; //Almacena la componente a la que pertenece cada nodo
int SCC; //Cantidad de componentes fuertemente conexas
int n, m; //Cantidad de nodos y aristas

void tarjan(int u) {
    low[u] = num[u] = cont++;
    st.push(u);
    vis[u] = true;

    for (auto &v : g[u]) {
        if (num[v] == -1) tarjan(v);
        if (vis[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
        while (true) {
            int v = st.top(); st.pop();
            vis[v] = false;
            comp[v] = SCC;
            if (u == v) break;
        }
        SCC++;
    }
}

void init() {
    cont = SCC = 0;
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        num[i] = -1; //no visitado
    }
}