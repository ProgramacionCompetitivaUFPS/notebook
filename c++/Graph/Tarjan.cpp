Algoritmo para hallar componentes fuertemente conexas(SCC) en grafos dirigidos.

int v, e; 
const int MAX = 5000; // Máxima cantidad de nodos
int dfs_low[MAX];
int dfs_num[MAX];
bool visited[MAX];
vector<int> s;
int dfsCont, cantSCC;
vector<int> ady[];
	
void tarjanSCC( int u ){
	dfs_low[u] = dfs_num[u] = dfsCont;
	dfsCont++;
	s.push_back(u);
	visited[u] = true;
		
	int j, v;
		
	for( j = 0; j < ady[u].size(); j++ ){
		v = ady[u][j] );
			
		if( dfs_num[v] == -1 ){
			tarjanSCC( v );
		}
			
		if( visited[v] ){
			dfs_low[u] = min( dfs_low[u], dfs_low[v] );
		}
	}
		
	if( dfs_low[u] == dfs_num[u] ){
		cantSCC++;
        /* ********************************************************* */
        /* Esta seccion se usa para imprimir las componentes conexas */
		cout << "COMPONENTE CONEXA #" << cantSCC << "\n";
		while( true ){
			v = s.back();
			s.pop_back();
			visited[v] = false;
			cout << v << "\n";
			if( u == v ) break;
		}
        /* ********************************************************** */
	}	
}

int main (){
	cantSCC = 0;

    for( int i = 0; i < v; i++ ){ //Por si el grafo no es conexo
        if( dfs_num[i] == -1 ){
            dfsCont = 0;
            s.clear();
            tarjanSCC(i);
        }
    }
}
	



