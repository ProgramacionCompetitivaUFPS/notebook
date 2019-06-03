Dados los nodos u y v de un arbol determina cual es el ancestro comun mas bajo entre u y v.
*Tambien puede determinar la arista de peso maximo entre los nodos u y v (Para esto quitar los "//")
SE DEBE EJECUTAR EL METODO build() ANTES DE UTILIZARSE

//struct edge { int v, w; };

const int MAX = 100005; //Cantidad maxima de nodos
const int LOG2 = 17; //log2(MAX)+1
//vector<edge> g[MAX]; //Lista de adyacencia
vector<int> g[MAX]; //Lista de adyacencia
int dep[MAX]; //Almacena la profundidad de cada nodo
int par[MAX][LOG2]; //Almacena los padres para responder las consultas
//int rmq[MAX][LOG2]; //Almacena los pesos para responder las consultas
int N, M; //Cantidad de nodos y aristas 

int lca(int u, int v) {
    //int ans = -1;
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int i = LOG2-1; i >= 0; i--) {
        if (diff & (1 << i)) {
            //ans = max(ans, rmq[u][i]);
            u = par[u][i];
        }
    }
    //if (u == v) return ans;
    if (u == v) return u;
    for (int i = LOG2-1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            //ans = max(ans, max(rmq[u][i], rmq[v][i]));
            u = par[u][i];
            v = par[v][i];
        }
    }
    //return max(ans, max(rmq[u][0], rmq[v][0]));
    return par[u][0];
}

void dfs(int u, int p, int d) {
    dep[u] = d;
    par[u][0] = p;
    for (auto v /*ed*/ : g[u]) {
        //int v = ed.v;
        if (v != p) {
            //rmq[v][0] = ed.w;
            dfs(v, u, d + 1);
        }
    }
}

void build() {
    for(int i = 0; i < N; i++) dep[i] = -1;
    for(int i = 0; i < N; i++) {
        if(dep[i] == -1) {
            //rmq[i][0] = -1;
            dfs(i, i, 0);
        }
    }
    for(int j = 0; j < LOG2-1; j++) {
        for(int i = 0; i < N; i++) {
            par[i][j+1] = par[ par[i][j] ][j];
            //rmq[i][j+1] = max(rmq[ par[i][j] ][j], rmq[i][j]);
        }
    }
}

void init() {
	for (int i = 0; i <= N; i++) {
		g[i].clear();
	}
}
