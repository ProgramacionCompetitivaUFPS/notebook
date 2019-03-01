Algoritmo para hallar el arbol cobertor mínimo de un grafo  no dirigido y conexo. Utiliza la técnica de Union-Find(Conjuntos disjuntos) para detectar que aristas generan ciclos.
Requiere de la struct Edge.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

struct edge { int u, v, w; };

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

const int MAXN = 100005;
const int MAXE = 200005;
int n, e;
edge arcos[MAXE];
vector<pair<int, int> > ady[MAXN];

void init() {
	for(int i = 0; i <= n; i++ ) {
		ady[i].clear();
		ds[i] = i;
	}
}

void kruskall() {
	sort(arcos, arcos+e, cmp);
	edge cur;
	for (int i = 0, sz = 0; i < e && sz < n-1; i++) {
		cur = arcos[i];
		if(find(cur.u) != find(cur.v)) {
			unite(cur.u, cur.v);
			ady[cur.u].push_back({cur.v, cur.w});
			ady[cur.v].push_back({cur.u, cur.w});
			sz++;
		}
	}
}
