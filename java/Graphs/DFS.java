Algoritmo de búsqueda en profundidad para grafos. Parte de un nodo inicial s visita a todos sus vecinos. DFS puede ser usado para contar la cantidad de componentes conexas en un grafo y puede ser modificado para que retorne información de los nodos dependiendo del problema. Permite hallar ciclos en un grafo.

import java.util.ArrayList;

static int v, e; //vertices, arcos
static int MAX=100005; 
static ArrayList<Integer> ady[] = new ArrayList[MAX];
static boolean marked[] = new boolean[MAX];

//Limpia las estrucuturas de datos
static void init(){
	 for (int j = 0; j <= v; j++) {
        marked[j] = false;
        ady[j] = new ArrayList<Integer>();
    }
}

//Recibe el nodo inicial s
static void dfs(int s){
	marked[s]=true;
	int i, next;

	for(i=0; i<ady[s].size(); i++){
		next=ady[s].get(i);
		if(!marked[next]){
			dfs(next);
		}
	}
}
