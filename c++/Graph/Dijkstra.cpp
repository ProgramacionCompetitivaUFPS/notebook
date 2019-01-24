Algoritmo que dado un grafo con pesos no negativos halla la ruta mínima entre un nodo inicial s y todos los demás nodos.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

#define Node pair<long long, int> //(PESO, NODO adyacente)

int n, e; //n = cantidad de nodos, e = cantidad de aristas
const int MAX = 100001; //Cantidad Maxima de Nodos
vector<Node> ady[MAX]; //Lista de Adyacencia del grafo
bool marked[MAX]; //Estructura auxiliar para marcar los nodos visitados
int previous[MAX]; //Estructura auxiliar para almacenar las rutas
long long dist[MAX]; //Estructura auxiliar para llevar las distancias a cada nodo

 //El metodo debe llamarse con el indice del nodo inicial
void dijkstra(int u) {
	priority_queue<Node, vector<Node>, greater<Node> > pq;
	long long weight;
	int act, next;
	pq.push({0, u});
	dist[u] = 0;
	while (!pq.empty()) {
		act = pq.top().second;
		pq.pop();
		if (!marked[act]) {
			marked[act] = 1;
			for(int j = 0; j < ady[act].size(); j++) {
				weight = ady[act][j].first;
				next = ady[act][j].second;
				if(!marked[next] && dist[next] > dist[act] + weight) {
					dist[next] = dist[act] + weight;
					previous[next] = act;
					pq.push({dist[next], next});
				}
			}
		}
	}
}

void init() {
    for(int i = 0; i <= n; i++) {
        ady[i].clear();
        dist[i] = LLONG_MAX;
        marked[i] = 0;
    }
}