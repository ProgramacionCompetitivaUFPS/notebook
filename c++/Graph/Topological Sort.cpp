Dado un grafo acíclico dirigido, ordena los nodos linealmente de tal manera que si existe una arista entre los nodos u y v entonces u aparece antes que v.
Este ordenamiento es una manera de poner todos los nodos en una línea recta de tal manera que las aristas vayan de izquierda a derecha.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

int n; //Cantidad de nodos del grafo
const int MAX=100005; //Cantidad máxima de nodos del grafo
vector<int> topoSort; //Ordenamiento topologico del grafo
vector<int> ady[MAX]; //Lista de adyacencia
bool marked[MAX]; //Estructura auxiliar para marcar los nodos visitados

//Recibe un nodo inicial u
void dfs( int u ){
	int i, v;
	marked[u] = 1;
	for( i = 0; i < ady[u].size(); i++){
		v = ady[u][i];
		if( !marked[v] ) dfs(v);
	}
	topoSort.push_back(u);
}

int main(){
	for(i=0; i<n; i++){
		if( !marked[i] )	dfs(i);
	}
	//imprimir topoSort en reversa :3
}

