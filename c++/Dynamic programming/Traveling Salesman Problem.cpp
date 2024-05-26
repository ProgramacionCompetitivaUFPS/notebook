Problema del viajero. Devuelve la ruta minima haciendo un tour visitando todas los nodos (ciudades) una unica vez.

const int MAX = 18;
int target; // Inicializarlo para (1<<N) - 1
int dist[MAX][MAX]; // Distancia entre cada par de nodos
int N;
int dp[(1<<MAX) + 2][MAX];
vector<int> rb;
const int INF = (int) (2e9);

// Llamar para TSP(0, -1) Si no empieza de ninguna ciudad especificia
// De lo contrario llamar TSP(0, 0)
int TSP(int mask, int u) {
    if (mask == target) {
        return 0;
        // O en su defecto el costo extra tras haber visitado todas las ciudades. EJ: Volver a la ciudad principal
    }
    if (u == -1) {
        int ans = INF;
        for (int i = 0; i < N; i++) {
            ans = min(ans, TSP(mask | (1<<i), i));
            // Agregar costo Extra desde el punto de partida si es necesario
        }
        return ans;
    }
    int &ans = dp[mask][u];
    if (ans != -1) return ans;
    ans = INF;
    for (int i = 0; i < N; i++) {
        if (!(mask & (1<<i))) 
            ans = min(ans, TSP(mask | (1<<i), i) + dist[u][i]);
    }
    return ans;
}

void build(int mask, int u) {
    if (mask == target) return; // Acaba el recorrido
    if (u == -1) {
        for (int i = 0; i < N; i++) {
            if (TSP(mask, u) == TSP(mask | (1<<i), i)) {
                rb.push_back(i);
                build(mask | (1<<i), i);
                return;
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            if (!(mask & (1<<i))) {
                if (TSP(mask, u) == TSP(mask | (1<<i), i) + dist[u][i]) {
                    rb.push_back(i);
                    build(mask | (1<<i), i);
                    return;
                }
            }
        }
    }
}
