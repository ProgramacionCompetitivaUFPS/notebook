Dados los nodos u y v de un arbol determina cual es el ancestro comun mas bajo entre u y v.
*Tambien puede determinar la arista de peso maximo/minimo entre los nodos u y v (Para esto quitar los "//")
Se debe ejecutar la funcion dfs() primero, el padre de la raiz es sí mismo, w es el valor a almacenar del padre.

const int N = 4e5+2, inf = 1e9, LOG2 = 20;
int dep[N]; // Profundidad de cada nodo
int par[LOG2][N]; // Sparse table para guardar los padres
//int rmq[LOG2][N]; // Sparse table para guardar pesos

struct edge { int v, w; };
vector<edge> g[N];

void dfs(int u, int p, int d, int w){
    dep[u] = d;
    par[0][u] = p;
    // rmq[0][u] = w;
    for(int j = 1; j < LOG2; j++){
        par[j][u] = par[j-1][par[j-1][u]];
        // rmq[j][u] = max(rmq[j-1][u], rmq[j-1][par[j-1][u]]);
    }
    for(auto &ed: g[u]){
        int v = ed.v;
        int val = ed.w;
        if(v == p)continue;
        dfs(v, u, d+1, val);
    }
}

int lca(int u, int v){
    // int ans = -1;
    if(dep[v] < dep[u])swap(u, v);
    int d = dep[v]-dep[u];
    for(int j = LOG2-1; j >= 0; j--){
        if(d >> j & 1){
            // ans = max(ans, rmq[j][v]);
            v = par[j][v];
        }
    }
    // if(u == v)return ans;
    if(u == v)return u;
    for(int j = LOG2-1; j >= 0; j--){
        if(par[j][u] != par[j][v]){
            // ans = max({ans, rmq[j][u], rmq[j][v]});
            u = par[j][u];
            v = par[j][v];
        }
    }
    // return max({ans, rmq[1][u], rmq[0][v]}); // si la info es de los nodos
    // return max({ans, rmq[0][u], rmq[0][v]}); // si la info es de las aristas
    return par[0][u];
}
