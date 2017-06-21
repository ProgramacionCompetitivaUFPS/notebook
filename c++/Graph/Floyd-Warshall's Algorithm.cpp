Algoritmo para grafos que halla la distancia mínima entre cualquier par de nodos. ady[i][j] guardará la distancia mínima entre el nodo i y el j.

int v, e; //vertices, arcos
const int MAX = 505; //Cantidad máxima de nodos del grafo
int ady[505][505]; //Matriz de adyacencia del grafo

void floydWarshall(){
   int k, i ,j;
    
    for( k = 0; k < v; k++ ){
        for( i = 0; i < v; i++ ){
            for( j = 0; j < v; j++ ){
                ady[i][j] = min( ady[i][j], ( ady[i][k] + ady[k][j] ) );
            }
        }
    }
}
