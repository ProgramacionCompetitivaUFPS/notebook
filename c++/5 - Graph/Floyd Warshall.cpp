Dado un grafo halla la distancia minima entre cualquier par de nodos. g[i][j] guardara la distancia minima entre el nodo i y el j.

const int inf = 1e9;
const int MX = 505; //Cantidad maxima de nodos
int g[MX][MX]; //Matriz de adyacencia
int n, m; //Cantidad de nodos y aristas

void floydWarshall() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            g[i][j] = (i == j ? 0 : inf);
        }
    }
}