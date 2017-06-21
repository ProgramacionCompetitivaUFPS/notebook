Algoritmo para hallar el arbol cobertor mínimo de un grafo  no dirigido y conexo. Utiliza la técnica de Union-Find(Conjuntos disjuntos) para detectar que aristas generan ciclos.
Requiere la clase Edge(con pesos).

static int v, e; //vertices, arcos
static int MAX=100005;     
static int parent[]= new int [MAX];
static ArrayList<Edge> edges;
static ArrayList<Edge> answer;

//UNION-FIND   
static int find(int i){
    parent[i] = ( parent[i] == i ) ? i : find(parent[i]);
    return parent[i];
}

static void unionFind(int x, int y){
    parent[ find(x) ] = find(y);
}

static void kruskall(){
    Edge actual;
    int aux, i, x,y;
    aux = i = 0;
    Collections.sort(edges);
        
    while( aux < (v-1) && i < edges.size() ){
        actual = edges.get(i);
        x = find(actual.src);
        y = find(actual.dest);

        if( x != y ){
            answer.add(actual);
            aux++;
            unionFind(x, y);
        }
        i++;
    }
}
