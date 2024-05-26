Dado un grafo no dirigido halla los puntos de articulación, puentes y componentes biconexas. Para construir el block cut tree quitar los comentarios.

struct edge {
    int u, v, comp; // A que componente biconexa pertenece
    bool bridge; // Si la arista es un puente
};

const int MX = 1e5+5; // Cantidad maxima de nodos
vector<int> g[MX]; // Lista de adyacencia
vector<edge> e; // Lista de aristas
stack<int> st;
int low[MX], num[MX], cont;
bool art[MX]; // Si el nodo es un punto de articulacion
// vector<set<int>> comps; // Componentes biconexas
// vector<vector<int>> tree; // Block cut tree
// vector<int> id; // Id del nodo en el block cut tree
int BCC; // Cantidad de componentes biconexas
int n, m; // Cantidad de nodos y aristas

void add_edge(int u, int v) {
    g[u].pb(e.size());
    g[v].pb(e.size());
    e.pb({u, v, -1, false});
}

void dfs(int u, int p = -1) {
    low[u] = num[u] = cont++;
    for (auto &i : g[u]) {
        edge &ed = e[i];
        int v = ed.u^ed.v^u;
        if (num[v] == -1) {
            st.push(i);
            dfs(v, i);
            if (low[v] > num[u]) 
                ed.bridge = true; // bridge
            if (low[v] >= num[u]) {
                art[u] = (num[u] > 0 || num[v] > 1); // articulation
                int last; // start biconnected
                // comps.pb({});
                do {
                    last = st.top(); st.pop();
                    e[last].comp = BCC;
                    // comps.back().insert(e[last].u);
                    // comps.back().insert(e[last].v);
                } while (last != i);
                BCC++; // end biconnected
            }
            low[u] = min(low[u], low[v]);
        } else if (i != p && num[v] < num[u]) {
            st.push(i);
            low[u] = min(low[u], num[v]);
        }
    }
}

void build_tree() {
    tree.clear(); id.resize(n);
    for (int u = 0; u < n; u++) {
        if (art[u]) {
            id[u] = tree.size();
            tree.pb({});
        }
    }
    for (auto &comp : comps) {
        int node = tree.size();
        tree.pb({});
        for (auto &u : comp) {
            if (art[u]) {
                tree[id[u]].pb(node);
                tree[node].pb(id[u]);
            } else id[u] = node;
        }
    }
}

void init() {
    cont = BCC = 0;
    // comps.clear();
    e.clear();
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        num[i] = -1; // no visitado
        art[i] = false;
    }
}
