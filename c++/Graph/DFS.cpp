Algoritmo de búsqueda en profundidad para grafos. Parte de un nodo inicial s visita a todos sus vecinos. DFS puede ser usado para contar la cantidad de componentes conexas en un grafo y puede ser modificado para que retorne información de los nodos dependiendo del problema. Permite hallar ciclos en un grafo.

int v, e; //vertices, arcos
int MAX=100005; 
vector<int> ady[MAX];
int marked[MAX];

void init(){
	for (int j = 0; j <= v; j++) {
       marked[j] = 0;
       ady[j].clear();
    }
}

static void dfs(int s){
	marked[s]=1;
	int i, next;

	for(i=0; i<ady[s].size(); i++){
		next=ady[s][i];
		if(marked[next]==0){
			dfs(next);
		}
	}
}
