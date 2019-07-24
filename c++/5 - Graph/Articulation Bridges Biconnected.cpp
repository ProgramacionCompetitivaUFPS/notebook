Dado un grafo no dirigido halla los puntos de articulación, puentes y componentes biconexas. Para construir el block cut tree quitar los comentarios.

struct edge {
	int u, v, comp; //A que componente biconexa pertenece
	bool bridge; //Si la arista es un puente
};

const int MAX = 100005; //Cantidad maxima de nodos
vector<int> g[MAX]; //Lista de adyacencia
vector<edge> e; //Lista de aristas
stack<int> st;
int low[MAX], num[MAX], cont;
bitset<MAX> art; //Si el nodo es un punto de articulacion
//vector<set<int>> comps; //Componentes biconexas
//<vector<int>> tree; //Block cut tree
//vector<int> id; //Id del nodo en el block cut tree
int cantBCC; //Cantidad de componentes biconexas
int N, M; //Cantidad de nodos y aristas

void add_edge(int u, int v){
	g[u].push_back(e.size());
	g[v].push_back(e.size());
	e.push_back({u, v, -1, false});
}

void dfs(int u, int p = -1) {
	low[u] = num[u] = cont++;
	for (int i : g[u]) {
		edge &ed = e[i];
		int v = ed.u^ed.v^u;
		if (num[v] == -1) {
			st.push(i);
			dfs(v, i);
			if (low[v] > num[u])
				ed.bridge = true; //bridge
			if (low[v] >= num[u]) {
				art[u] = (num[u] > 0 || num[v] > 1); //articulation
				int last; //start biconnected
				//comps.push_back({});
				do {
					last = st.top(); st.pop();
					e[last].comp = cantBCC;
					//comps.back().insert(e[last].u);
					//comps.back().insert(e[last].v);
				} while (last != i);
				cantBCC++; //end biconnected
			}
			low[u] = min(low[u], low[v]);
		} else if (i != p && num[v] < num[u]) {
			st.push(i);
			low[u] = min(low[u], num[v]);
		}
	}
}

void build_tree() {
	tree.clear(); id.resize(N);
	for (int u = 0; u < N; u++) {
		if (art[u]) {
			id[u] = tree.size();
			tree.push_back({});
		}
	}
	for (auto &comp : comps) {
		int node = tree.size();
		tree.push_back({});
		for (int u : comp) {
			if (art[u]) {
				tree[id[u]].push_back(node);
				tree[node].push_back(id[u]);
			} else id[u] = node;
		}
	}
}

void init() {
	art = cont = cantBCC = 0;
	//comps.clear();
	for (int i = 0; i <= N; i++) {
		g[i].clear();
		num[i] = -1; //no visit
	}
}
