#include <bits/stdc++.h>
using namespace std;

//ALGORITMO TARJAN
//Algoritmo para hallar componentes fuertemente conexas(SCC) en grafos dirigidos.
//Divide un grafo en subgrafos de acuerdo a los componentes fuertemente conexos

int v, e; 
const int MAX = 5000; 
vector<int> ady[MAX];
int dfs_low[MAX]; 
int dfs_num[MAX]; 
bool marked[MAX];  
vector<int> s; // Guarda los nodos de los subgrafos de acuerdo a si son componentes conexos 
int dfsCont, cantSCC; 

void init(){
    for( int j = 0; j <= v; j++ ) {
        dfs_num[j] = -1;
        dfs_low[j] = 0;
	ady[i].clear();
    }
}
	
void tarjanSCC( int u ){
	dfs_low[u] = dfs_num[u] = dfsCont;
	dfsCont++;
	s.push_back(u);
	marked[u] = true;
		
	int j, v;
		
	for( j = 0; j < ady[u].size(); j++ ){
		v = ady[u][j];
			
		if( dfs_num[v] == -1 ){
			tarjanSCC( v );
		}
			
		if( marked[v] ){
			dfs_low[u] = min( dfs_low[u], dfs_low[v] );
		}
	}
		
	if( dfs_low[u] == dfs_num[u] ){
		cantSCC++;
		//Imprime los subgrafos de las componentes conexas
		cout << "COMPONENTE CONEXA #" << cantSCC << "\n";
		while( true ){
			v = s.back();
			s.pop_back();
			marked[v] = false;
			cout << v << "\n";
			if( u == v ) break;
		}
	}	
}

int main (){
    int origen, destino;
    
    //Al iniciar cada caso de prueba
    cin >> v >> e;
    cantSCC = 0;
    
    while( e > 0 ){
      cin >> origen >> destino;
      //origen--;destino--;  //Si los datos empiezan en 1 
      ady[origen].push_back(destino);
      //ady[destino].push_back(origen);
      e--;
    }
	
    init();
	
    //Ejemplo: 5 5 0 2 0 3 1 0 2 1 3 4
    //El ejemplo divide el grafo en 3 subgrafos
    for( int i = 0; i < v; i++ ){ //Por si el grafo no es conexo
        if( dfs_num[i] == -1 ){
            dfsCont = 0;
            s.clear();
            tarjanSCC(i);
        }
    }
}


