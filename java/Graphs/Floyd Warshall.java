Algoritmo para grafos que halla la distancia mínima entre cualquier par de nodos. ady[i][j] guardará la distancia mínima entre el nodo i y el j.
Ajustar los tipos de datos segun el problema.

static int v, e; //vertices, arcos
static int MAX = 505;     
static int ady[][] = new int [MAX][MAX];

//Método para limpiar las estructuras de datos
static void init() {
    int i, j;
    for(i = 0; i < v; i++){
        for(j = 0; j < v; j++){
            ady[i][j] = Integer.MAX_VALUE;
        }
    }
}

static void floydWarshall(){
    int i,j,k, aux;
    
    for( k = 0; k < v; k++ ){
        for( i = 0; i < v; i++ ){
            for( j = 0; j < v; j++ ){
                ady[i][j] = min( ady[i][j], ( ady[i][k] + ady[k][j] ) );
            }
        }
    }
}
