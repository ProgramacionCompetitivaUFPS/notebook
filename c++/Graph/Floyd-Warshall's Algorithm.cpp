Algoritmo para grafos que halla la distancia mínima entre cualquier par de nodos. Matrix[i][j] guardará la distancia mínima entre el nodo i y el j.

int v, e; //vertices, arcos
const int MAX = 505; //Cantidad máxima de nodos del grafo
int matrix[505][505]; //Matriz de adyacencia del grafo

/*La ruta más corta entre cada par de nodos i,j se almacenará en 
matrix[i][j] */
void floydWarshall(){
   int k = 0;
   int aux, i ,j;
    
   while( k < v ){
      for( i = 0; i < v; i++ ){
         if( i != k ){
            for( j = 0; j < v; j++ ){
               if( j != k ){
                  aux = matrix[i][k] + matrix[k][j];
                  if( aux < matrix[i][j] && aux > 0){ 
                     matrix[i][j] = aux;
                  }
               }
            }
         }
      }
      k++;
   }
}