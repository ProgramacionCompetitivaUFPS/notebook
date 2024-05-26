// Problema del viajero. Devuelve la ruta minima haciendo un tour visitando todas los nodos (ciudades) una unica vez.

static final int MAX = 18;
static int target; // Inicializarlo para (1<<N) - 1
static int dist[][] = new int [MAX][MAX]; // Distancia entre cada par de nodos
static int N;
static int dp[][] = new int[(1<<MAX) + 2][MAX];
static ArrayList<Integer> rb = new ArrayList<>();
static final int INF = (int) (2e9);

// Llamar para TSP(0, -1) Si no empieza de ninguna ciudad especificia
// De lo contrario llamar TSP(0, 0)
static int TSP(int mask, int u) {
    if (mask == target) {
        return 0;
        // O en su defecto el costo extra tras haber visitado todas las ciudades. EJ: Volver a la ciudad principal
    }
    if (u == -1) {
        int ans = INF;
        for (int i = 0; i < N; i++) {
            ans = Math.min(ans, TSP(mask | (1<<i), i));
            // Agregar costo Extra desde el punto de partida si es necesario
        }
        return ans;
    }
    int ans = dp[mask][u];
    if (ans != -1) return ans;
    ans = INF;
    for (int i = 0; i < N; i++) {
        if ((mask & (1<<i))==0) 
            ans = Math.min(ans, TSP(mask | (1<<i), i) + dist[u][i]);
    }
    return ans;
}

static void build(int mask, int u) {
    if (mask == target) return; // Acaba el recorrido
    if (u == -1) {
        for (int i = 0; i < N; i++) {
            if (TSP(mask, u) == TSP(mask | (1<<i), i)) {
                rb.add(i);
                build(mask | (1<<i), i);
                return;
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            if ((mask & (1<<i))==0) {
                if (TSP(mask, u) == TSP(mask | (1<<i), i) + dist[u][i]) {
                    rb.add(i);
                    build(mask | (1<<i), i);
                    return;
                }
            }
        }
    }
}
