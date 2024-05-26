Dado un grafo con pesos halla su arbol cobertor minimo. Debe agregarse Disjoint Set.

struct edge { int u, v, w; };

bool cmp(edge &a, edge &b) {
    return a.w < b.w;
}

const int MX = 1e5+5; // Cantidad maxima de nodos
vector<pii> g[MX]; // Lista de adyacencia
vector<edge> e; // Lista de aristas
int n, m; // Cantidad de nodos y aristas

void kruskall() {
    sort(e.begin(), e.end(), cmp);
    dsu ds(n);
    int cnt = 0;
    for (auto &ed : e) {
        if (ds.find(ed.u) != ds.find(ed.v)) {
            ds.unite(ed.u, ed.v);
            g[ed.u].pb({ed.v, ed.w});
            g[ed.v].pb({ed.u, ed.w});
            if (++cnt == n-1) break;
        }
    }
}

void init() {
    e.clear();
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
