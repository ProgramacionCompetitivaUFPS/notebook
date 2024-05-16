const int MAX_N = 1000;
const int MAX_W = 10000;
const int INF = (int) (2e9);

int dp[MAX_N + 5][MAX_W + 5];
int gold[MAX_N];
int weight[MAX_N];
int N;
vector<int> rb;

// mochila TOP_DOWN. NECESITA INICIALIZARSE ANTES DP EN -1
int f(int i, int w){
    if(w < 0) return -INF;
    if(i == N) return 0;
    int &ans = dp[i][w];
    if(ans != -1) return ans;
    ans = max(f(i + 1, w), f(i + 1, w - weight[i]) + gold[i]);
    return ans;
}

// BOTTOM_UP MOCHILA. ACCEDER COMO dp[0][W]
void mochila(){
    for(int i = 0; i <= MAX_W; i++) dp[N][i] = 0;
    for(int i = N - 1; i >= 0; i--){
        for(int w = 0; w <= MAX_W; w++){
            dp[i][w] = dp[i + 1][w];
            if(w - weight[i] >= 0) dp[i][w] = max(dp[i][w], dp[i + 1][w - weight[i]] + gold[i]);
        }
    }
}

// MOCHILA OPTIMIZANDO MEMORIA. ACCEDER COMO dp_opt[0][W]
int dp_opt[2][MAX_W + 5];
void mochila_opt(){
    for(int i = 0; i <= MAX_W; i++) dp[N%2][i] = 0;
    for(int i = N - 1; i >= 0; i--){
        for(int w = 0; w <= MAX_W; w++){
            dp_opt[i%2][w] = dp_opt[(i + 1)%2][w];
            if(w - weight[i] >= 0) dp_opt[i%2][w] = max(dp_opt[i%2][w], dp_opt[(i + 1)%2][w - weight[i]] + gold[i]);
        }
    }
}

// RECONSTRUIR SOLUCION. GUARDA LOS INDICES DE LOS ELEMENTOS USADOS. NO FUNCIONA CON MOCHILA OPTIMIZADA.
// ADVERTENCIA: Si existen multiples soluciones reconstruye la que primero aparezca. Para la ultima recorrer al revés
void build(int W){
    rb.clear();
    for(int i = 0; i < N && W > 0; i++){
        if(W - weight[i] >= 0 && dp[i][W] == dp[i + 1][W - weight[i]] + gold[i]) 
            rb.push_back(i);
    }
}
