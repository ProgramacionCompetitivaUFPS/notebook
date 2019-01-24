Dados los nodos a y b de un arbol determina cual es el ancestro comun mas bajo entre a y b.
*Tambien puede determinar la arista de peso maximo entre los nodos a y b (Para esto quitar los "//" y agregar la clase Node)
SE DEBE EJECUTAR EL METODO build() ANTES DE UTILIZARSE

static int n, e; //Cantidad de nodos y aristas 
static int MAX = 100005; //Cantidad maxima de nodos
static int LOG2 = 17; //log2(MAX)
//static ArrayList<Node> ady[] = new ArrayList[MAX]; //Lista de adyacencia
static ArrayList<Integer> ady[] = new ArrayList[MAX]; //Lista de adyacencia
static int dep[] = new int[MAX]; //Almacena la profundidad de cada nodo
static int par[][] = new int[MAX][LOG2]; //Almacena los padres para responder las consultas
//static int rmq[][] = new int[MAX][LOG2]; //Almacena los pesos para responder las consultas

static int lca(int a, int b) {
	//int ans = -1;
    if (dep[a] < dep[b]) { int c=a;a=b;b=c; }
    int diff = dep[a] - dep[b];
    for (int i = LOG2-1; i >= 0; i--) {
        if ((diff & (1 << i)) > 0) {
        	//ans = Math.max(ans, rmq[a][i]);
        	a = par[a][i];
        }
    }
    //if (a == b) return ans;
	if (a == b) return a;
    for (int i = LOG2-1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
        	//ans = Math.max(ans, Math.max(rmq[a][i], rmq[b][i]));
            a = par[a][i];
            b = par[b][i];
        }
    }
	//return Math.max(ans, Math.max(rmq[a][0], rmq[b][0]));
	return par[a][0];
}

static void dfs(int u, int p, int d) {
	dep[u] = d;
	par[u][0] = p;
	for (int v /*Node nx*/ : ady[u]) {
		//int v = nx.adjacent;
		if (v != p) {
			//rmq[v][0] = nx.cost;
			dfs(v, u, d + 1);
		}
	}
}

static void build() {
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
			//rmq[i][j+1] = Math.max(rmq[ par[i][j] ][j], rmq[i][j]);
		}
	}
}