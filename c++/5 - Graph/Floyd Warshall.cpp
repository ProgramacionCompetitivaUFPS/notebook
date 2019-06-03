Dado un grafo halla la distancia mínima entre cualquier par de nodos. g[i][j] guardará la distancia mínima entre el nodo i y el j.

#define INF (1<<30)

const int MAX = 505; //Cantidad maxima de nodos
int g[MAX][MAX]; //Matriz de adyacencia
int N, M; //Cantidad de nodos y aristas

void floydWarshall() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void init() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            g[i][j] = INF;
        }
    }
}
