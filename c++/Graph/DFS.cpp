Algoritmo de búsqueda en profundidad para grafos. Parte de un nodo inicial s visita a todos sus vecinos. DFS puede ser usado para contar la cantidad de componentes conexas en un grafo y puede ser modificado para que retorne información de los nodos dependiendo del problema. Permite hallar ciclos en un grafo.

int v, e; //vertices, arcos
const int MAX=100005; //Cantidad máxima de nodos del grafo
vector<int> ady[MAX]; //lista de Adyacencia del grafo
int marked[MAX]; //Estructura auxiliar para marcar los nodos ya visitados

/*Debe llamarse al iniciar cada caso de prueba luego de haber leido v
Limpia todas las estructuras de datos.*/
void init(){
	for(int j = 0; j <= v; j++) {
    marked[j] = 0;
    ady[j].clear();
  }
}

/*Este método se llama con el indice del nodo desde el que se desea comenzar
el recorrido.*/
static void dfs(int s){
	marked[s] = 1;
	int i, next;

	for( i = 0; i < ady[s].size(); i++ ){
		next = ady[s][i];
		if( marked[next] == 0 ){
			dfs(next);
		}
	}
}
