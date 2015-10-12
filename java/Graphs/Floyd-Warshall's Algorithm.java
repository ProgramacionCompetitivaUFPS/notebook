Algoritmo para grafos que halla la distancia mínima entre cualquier par de nodos. Matrix[i][j] guardará la distancia mínima entre el nodo i y el j.
Ajustar los tipos de datos segun el problema.

static int v, e; //vertices, arcos
static int MAX=505;     
static int matrix[][]=new int [MAX][MAX];

//Método para limpiar las estructuras de datos
static void init() {
    int i, j;
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            matrix[i][j]=-1;
        }
    }
}

static void floydWarshall(){
    int i,j,k, aux;
    k=0;
    while(k<v){
        for(i=0; i<v; i++){
            if(i!=k){
                for(j=0; j<v; j++){
                    if(j!=k){
                        aux=matrix[i][k]+matrix[k][j];
                        if(aux<matrix[i][j] && aux>0){ 
                            matrix[i][j]=aux;
                        }
                    }
                }
            }
        }
        k++;
    }
}
