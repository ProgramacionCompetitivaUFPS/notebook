Algoritmo para hallar el arbol cobertor mínimo de un grafo  no dirigido y conexo. Utiliza la técnica de Union-Find(Conjuntos disjuntos) para detectar que aristas generan ciclos.

import java.util.ArrayList;
import java.util.Collections;


static int v, e; //vertices, arcos
static int MAX=100005;     
static int parent[]= new int [MAX];
static int rank[]= new int [MAX]; 
static ArrayList<Edge> edges;
static ArrayList<Edge> answer;

//limpiar las estructuras de datos    
static void init() {
    edges=new ArrayList<Edge>();
    answer=new ArrayList<Edge>();
    for (int j = 0; j <= v; j++) {
        parent[j] = j;
        rank[j] = 0;
    }
}

//UNION-FIND   
static int find(int i){
    if(parent[i]!=i){
        parent[i]=find(parent[i]);
    }
        return parent[i];
}

static void unionFind(int x, int y){
    int xroot = find(x);
    int yroot = find(y);
     
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
     
    else{
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

static void kruskall(){
    Edge actual;
    int aux=0;
    int i=0;
    int x,y;
    Collections.sort(edges);
        
    while(aux<(v-1)){
        actual=edges.get(i);
        x=find(actual.src);
        y=find(actual.dest);

        if(x!=y){
            answer.add(actual);
            aux++;
            unionFind(x, y);
        }
        i++;
    }
}

static class Edge implements Comparable<Edge> {

    public int src, dest, weight;
    
    public Edge(int s, int d, int w) {
        this.src = s;
        this.dest = d;
        this.weight=w;
    }
    
    @Override
    public int compareTo(Edge o) {
        return this.weight-o.weight;
    }
}
