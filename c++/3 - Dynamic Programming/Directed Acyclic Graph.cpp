Problemas clasicos con DAG

const int INF = 1e9;
const int MAX = 1000;
int init, fin;
int dp[MAX];
vector<int> g[MAX]; //USADO PARA ARISTAS NO PONDERADAS
vector<pair<int, int>> gw[MAX]; //PARA ARISTAS PONDERADAS First: Nodo vecino. Second = Peso de la arista

//Funcion para calcular el numero de formas de ir del nodo u al nodo end
//LLamar para nodo inicial (init)
int ways(int u){
    if(u == fin) return 1;
    int &ans = dp[u];
    if(ans != -1) return ans;
    ans = 0;
    for(auto v: g[u]){
        ans += ways(v);
    }
    return ans;
}

//MINIMO CAMINO DESDE U HASTA END. LLAMAR PARA INIT
int min_way(int u){
    if(u == fin) return 0;
    int &ans = dp[u];
    if(ans != -1) return ans;
    ans = INF;
    for(auto v: gw[u]){
        ans = min(ans, min_way(v.first) + v.second);
    }
    return ans;
}
