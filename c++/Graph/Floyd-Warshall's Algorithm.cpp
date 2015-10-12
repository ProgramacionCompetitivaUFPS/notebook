Algoritmo para grafos que halla la distancia mínima entre cualquier par de nodos. Matrix[i][j] guardará la distancia mínima entre el nodo i y el j.

#define Node pair<int,long long> //(Vertice adyacente, peso)

int v,e;
int matrix[505][505];

void floydWarshall(){
    int k=0;
    int aux, i ,j;
    
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