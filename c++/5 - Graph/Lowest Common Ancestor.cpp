Dados los nodos u y v de un arbol determina cual es el ancestro comun mas bajo entre u y v.
*Tambien puede determinar la arista de peso maximo/minimo entre los nodos u y v (Para esto quitar los "//")
Se debe ejecutar la funcion build() primero.

//struct edge { int v, w; };

const int MX = 1e5+5; //Cantidad maxima de nodos
const int LG = log2(MX)+1;
//vector<edge> g[MX]; //Lista de adyacencia
vector<int> g[MX]; //Lista de adyacencia
vector<int> dep; //Almacena la profundidad de cada nodo
int par[LG][MX]; //Almacena los padres para responder las consultas
//int rmq[LG][MX]; //Almacena los pesos para responder las consultas
int n, m; //Cantidad de nodos y aristas 

void pre(int u, int p, int d) {
    dep[u] = d;
    par[0][u] = p;
    for (auto &v /*ed*/ : g[u]) {
        //int v = ed.v;
        if (v != p) {
            //rmq[0][v] = ed.w;
            pre(v, u, d + 1);
        }
    }
}

void build() {
    dep.assign(n, -1);
    for (int i = 0; i < n; i++) {
        if (dep[i] == -1) {
            //rmq[0][i] = -1;
            pre(i, i, 0);
        }
    }
    for (int j = 0; j < LG-1; j++) {
        for (int i = 0; i < n; i++) {
            par[j+1][i] = par[j][ par[j][i] ];
            //rmq[j+1][i] = max(rmq[j][ par[j][i] ], rmq[j][i]);
        }
    }
}

int lca(int u, int v) {
    //int ans = -1;
    if (dep[u] < dep[v]) swap(u, v);
    int dif = dep[u] - dep[v];
    for (int i = LG-1; i >= 0; i--) {
        if (dif & (1<<i)) {
            //ans = max(ans, rmq[i][u]);
            u = par[i][u];
        }
    }
    //if (u == v) return ans;
    if (u == v) return u;
    for (int i = LG-1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            //ans = max(ans, max(rmq[i][u], rmq[i][v]));
            u = par[i][u];
            v = par[i][v];
        }
    }
    //return max(ans, max(rmq[0][u], rmq[0][v]));
    return par[0][u];
}

void init() {
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}