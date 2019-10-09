Dado un grafo con pesos halla su árbol cobertor mínimo.
IMPORTANTE: Debe agregarse Disjoint Set.

struct edge { int u, v, w; };

bool cmp(edge &a, edge &b) {
	return a.w < b.w;
}

const int MAX = 100005; //Cantidad maxima de nodos
vector<pair<int, int> > g[MAX]; //Lista de adyacencia
vector<edge> e; //Lista de aristas
int N, M; //Cantidad de nodos y aristas

void kruskall() {
	sort(e.begin(), e.end(), cmp);
	dsu ds(N);
	int sz = 0;
	for (auto &ed : e) {
		if (ds.find(ed.u) != ds.find(ed.v)) {
			ds.unite(ed.u, ed.v);
			g[ed.u].push_back({ed.v, ed.w});
			g[ed.v].push_back({ed.u, ed.w});
			if (++sz == N-1) break;
		}
	}
}

void init() {
	e.clear();
	for (int i = 0; i <= N; i++) {
		g[i].clear();
	}
}
