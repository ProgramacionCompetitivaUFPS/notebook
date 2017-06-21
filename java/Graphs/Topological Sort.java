Dado un grafo acíclico y dirigido, ordena los nodos linealmente de tal manera que si existe una arista entre los nodos u y v entonces u aparece antes que v.
Este ordenamiento es una manera de poner todos los nodos en una línea recta de tal manera que las aristas vayan de izquierda a derecha.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

static int v, e; //vertices, arcos
static int MAX=100005; //Cantidad máxima de nodos del grafo
static ArrayList<Integer> ady[] = new ArrayList[MAX]; //Lista de adyacencia
static ArrayList<Integer> topoSort; //Lista de adyacencia
static boolean marked[] = new boolean[MAX]; //Estructura auxiliar para marcar los grafos visitados

//Recibe un nodo inicial u
static void dfs( int u ){
	int i, v;
	marked[u] = 1;
	for( i = 0; i < ady[u].size(); i++){
		v = ady[u].get(i);
		if( !marked[v] ) dfs(v);
	}
	topoSort.add(u);
}

public static void main( String args[]){
	for(i=0; i<v; i++){
		if( !marked[i] )	dfs(i)
	}
	//imprimir topoSort en reversa :3
}

