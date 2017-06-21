Determina si un Grafo DIRIGIDO tiene o no ciclos.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

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

/*
Este metodo debe ser llamado desde un nodo inicial u.
Cortara su ejecucion en el momento que encuentre algun ciclo en el grafo.
*/
void graphCheck( int u ){
	int j, next;
	
	if( loops ) return;
	
	dfs_num[u] = 2;
	
	for(j = 0; j < ady[u].size(); j++ ){
		next = ady[u][j];
		
		if( dfs_num[next] == -1 )	graphCheck( next );
		else if( dfs_num[next] == 2 ){
			loops = true;
			break;
		}
	}
	
	dfs_num[u] = 3;
}


int main(){
	for( int s = 1; s <= v && !loops; s++ ){ //Por si el grafo es NO conexo
		if( dfs_num[s] == -1 ) graphCheck(s);
	}
}