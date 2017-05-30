Determina si un Grafo DIRIGIDO tiene o no ciclos.

const int MAX = 10010; //Cantidad maxima de nodos
int v; //Cantidad de Nodos del grafo
vector<int> ady[MAX]; //Estructura para almacenar el grafo
int dfs_num[MAX]; 
bool loops; //Bandera de ciclos en el grafo

/* DFS_NUM STATES
	2 - Explored
	3 - Visited
 	-1 - Unvisited
*/

/* Se debe llamar este metodo apenas se inicia cada caso de prueba */
void init(){
	int i;
	
	loops = false;
	
	for(i = 0; i <= v; i++ ){
		dfs_num[i] = -1;
		ady[i].clear();
	}
}

/*
Este metodo debe ser llamado desde un nodo inicial.
Cortara su ejecucion en el momento que encuentre algun ciclo en el grafo.
*/
void graphCheck( int u){
	int j, next;
	
	if( loops ) return;
	
	dfs_num[u] = 2;
	
	for(j = 0; j < ady[u].size(); j++ ){
		next = ady[u][j];
		
		if( dfs_num[next] == -1 ){
			graphCheck( next );
		}else if( dfs_num[next] == 2 ){
			loops = true;
			break;
		}
	}
	
	dfs_num[u] = 3;
}


int main(){
	cin >> v;
	
	init(); //llamado al metodo justo despues de leer la cantidad de nodos del grafo.
	
	for( s = 1; s <= v && !loops; s++ ){
		if( dfs_num[s] == -1 ) graphCheck(s);
	}
	
	//La variable loops guarda si el grafo tiene o no algun ciclo :)
	
	return 0;
}