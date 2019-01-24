Dados los nodos a y b de un arbol determina cual es el ancestro comun mas bajo entre a y b.
*Tambien puede determinar la arista de peso maximo entre los nodos a y b (Para esto quitar los "//")
SE DEBE EJECUTAR EL METODO build() ANTES DE UTILIZARSE

//#define Node pair<int, int> //(PESO, NODO adyacente)

int n, e; //Cantidad de nodos y aristas 
const int MAX = 100005; //Cantidad maxima de nodos
const int LOG2 = 17; //log2(MAX)
//vector<Node> ady[MAX]; //Lista de adyacencia
vector<int> ady[MAX]; //Lista de adyacencia
int dep[MAX]; //Almacena la profundidad de cada nodo
int par[MAX][LOG2]; //Almacena los padres para responder las consultas
//int rmq[MAX][LOG2]; //Almacena los pesos para responder las consultas

int lca(int a, int b) {
	//int ans = -1;
    if (dep[a] < dep[b]) swap(a, b);
    int diff = dep[a] - dep[b];
    for (int i = LOG2-1; i >= 0; i--) {
        if (diff & (1 << i)) {
        	//ans = max(ans, rmq[a][i]);
        	a = par[a][i];
        }
    }
    //if (a == b) return ans;
	if (a == b) return a;
    for (int i = LOG2-1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
        	//ans = max(ans, max(rmq[a][i], rmq[b][i]));
            a = par[a][i];
            b = par[b][i];
        }
    }
	//return max(ans, max(rmq[a][0], rmq[b][0]));
	return par[a][0];
}

void dfs(int u, int p, int d) {
	dep[u] = d;
	par[u][0] = p;
	for (auto v /*nx*/ : ady[u]) {
		//int v = nx.second;
		if (v != p) {
			//rmq[v][0] = nx.first;
			dfs(v, u, d + 1);
		}
	}
}

void build() {
	for(int i = 0; i < n; i++) dep[i] = -1;
	for(int i = 0; i < n; i++) {
		if(dep[i] == -1) {
			//rmq[i][0] = -1;
			dfs(i, i, 0);
		}
	}
	for(int j = 0; j < LOG2-1; j++) {
		for(int i = 0; i < n; i++) {
			par[i][j+1] = par[ par[i][j] ][j];
			//rmq[i][j+1] = max(rmq[ par[i][j] ][j], rmq[i][j]);
		}
	}
}