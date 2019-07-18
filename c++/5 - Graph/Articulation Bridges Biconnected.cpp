Dado un grafo no dirigido halla los puntos de articulación, puentes y componentes biconexas.

struct edge {
	int u, v, comp; //A que componente biconexa pertenece
	bool bridge; //Si la arista es un puente
};

const int MAX = 100005; //Cantidad maxima de nodos
vector<int> g[MAX]; //Lista de adyacencia
vector<edge> e; //Lista de aristas
stack<int> st;
int low[MAX], num[MAX], cont;
int art[MAX]; //si != 0 el nodo es un punto de articulacion 
int cantBC; //Cantidad de componentes biconexas
int N, M; //Cantidad de nodos y aristas

void add_edge(int u, int v){
	g[u].pb(e.size());
	g[v].pb(e.size());
	e.pb({u, v, -1, false});
}

void dfs(int u, int p = -1) {
	low[u] = num[u] = cont++;
	for (int id : g[u]) {
		edge &ed = e[id];
		int v = ed.u^ed.v^u;
		if (num[v] == -1) {
			st.push(id);
			dfs(v, id);
			if (low[v] > num[u])
				ed.bridge = true; //bridge
			if (low[v] >= num[u]) {
				art[u]++; //articulation
				int last; //start biconnected
				do {
					last = st.top(); st.pop();
					e[last].comp = cantBC;
				} while (last != id);
				cantBC++; //end biconnected
			}
			low[u] = min(low[u], low[v]);
		} else if (id != p && num[v] < num[u]) {
			st.push(id);
			low[u] = min(low[u], num[v]);
		}
	}
	art[u] -= (p == -1);
}

void init() {
    cont = cantBC = 0;
    for (int i = 0; i <= N; i++) {
        g[i].clear();
        num[i] = -1; //no visit
        art[i] = 0; //no articulation point
    }
}
