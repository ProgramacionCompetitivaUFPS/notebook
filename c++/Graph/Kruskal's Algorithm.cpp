Algoritmo para hallar el arbol cobertor mínimo de un grafo  no dirigido y conexo. Utiliza la técnica de Union-Find(Conjuntos disjuntos) para detectar que aristas generan ciclos.
Para hallar los 2 arboles cobertores minimos, se debe ejecutar el algoritmo v-1 veces, en cada una de ellas dscartar una de las aristas previamente elegidas en el arbol.

struct Edge{
    int origen, destino, peso;

    bool operator!=(const Edge& rhs) const{
        if(rhs.origen!=origen || rhs.destino!=destino || rhs.peso!=peso){
            return true;
        }
        return false;
    }
};

int v,e;
int MAX=10001;
int parent[MAX];
int rank[MAX]; 
Edge edges[MAX];
Edge answer[MAX];

void init(){
    for(int i=0; i<v; i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int cmp(const void* a, const void* b)
{   
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->peso > b1->peso;
}

int find(int i){
    if(parent[i]!=i){
        parent[i]=find(parent[i]);
    }
    return parent[i];
}

void unionFind(int x, int y){
    int xroot = find(x);
    int yroot = find(y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by rank)
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else{
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskall(){
    Edge actual;
    int aux=0;
    int i=0;
    int x,y;
    qsort(edges, e, sizeof(edges[0]), cmp);

    while(aux<v-1){
        actual=edges[i];
        x=find(actual.origen);
        y=find(actual.destino);

        if(x!=y){
            answer[aux]=actual;
            aux++;
            unionFind(x, y);
        }
        i++;
    }
}
