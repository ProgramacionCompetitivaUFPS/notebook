Algoritmo para hallar el arbol cobertor mínimo de un grafo  no dirigido y conexo. 
Requiere de la clase Node

static int v, e; //vertices, arcos
static int MAX=100005; 
static ArrayList<Node> ady[] = new ArrayList[MAX];
static boolean marked[] = new boolean[MAX];
static int rta;
static PriorityQueue<Node> pq;

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