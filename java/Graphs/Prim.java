Algoritmo para hallar el arbol cobertor mínimo de un grafo  no dirigido y conexo. 

import java.util.*;

static int v, e; //vertices, arcos
static int MAX=100005; 
static ArrayList<Node> ady[] = new ArrayList[MAX];
static boolean marked[] = new boolean[MAX];
static int rta;
static PriorityQueue<Node> pq;

//limpiar las estructuras de datos    
static void init() {
	rta = 0;
	pq = new PriorityQueue<Node>();
    for (int j = 0; j <= v; j++) {
        marked[j] = false;
        ady[j] = new ArrayList<Node>();
    }
}

static void prim(){
	process(0); //Nodo inicial;
	int u, w;
 
	while( pq.size() > 0 ){
		u = pq.peek().adjacent;
		w = pq.peek().cost;
 
		pq.poll();
 
		if( !marked[u] ){
			rta += w;
			process(u);
		}
	}
}
 
static void process( int u ){
	marked[u] = true;
	int i, v;
 
	for( i = 0; i < ady[u].size(); i++ ){
		v = ady[u].get(i).adjacent;
        if( !marked[v] ){
			pq.add( new Node( v, ady[u].get(i).cost ) );	
		}
	}
}

static class Node implements Comparable<Node> {
	public int adjacent;
    public int cost;
 
	public Node(int ady, int c) {
	    this.adjacent = ady;
	    this.cost = c;
    }
 
	@Override
	public int compareTo(Node o) {
	    if (this.cost >= o.cost)  return 1;
        else    return -1;
	}
} 