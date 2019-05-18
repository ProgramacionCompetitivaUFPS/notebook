ALgoritmo que dado un grafo con pesos no negativos halla la ruta mínima entre un nodo inicial s y todos los demás nodos.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

static int v, e; //v = cantidad de nodos, e = cantidad de aristas
static int MAX=100005; //Cantidad Máxima de Nodos
static ArrayList<Node> ady[] = new ArrayList[MAX]; //Lista de Adyacencia del grafo
static boolean marked[] = new int[MAX]; //Estructura auxiliar para marcar los nodos visitados
static long distance[] = new long[MAX]; //Estructura auxiliar para llevar las distancias a cada nodo
static int prev[] = new int[MAX]; //Estructura auxiliar para almacenar las rutas
    
//Recibe el nodo inicial s
static void dijkstra( int s ) {
    PriorityQueue<Node> pq = new PriorityQueue<Node>();
    pq.add(new Node(s, 0));//se inserta a la cola el nodo Inicial.
    distance[s] = 0;
    int actual, j, adjacent;
    long weight;
    Node x;

    while( pq.size() > 0 ) {
        actual = pq.peek().adjacent;
        pq.poll();
        if ( !marked[actual] ) {
            marked[actual] = true;
            for (j = 0; j < ady[actual].size(); j++) {
                adjacent = ady[actual].get(j).adjacent;
                weight = ady[actual].get(j).cost;
                if ( !marked[adjacent] ) {
                    if (distance[adjacent] > distance[actual] + weight) {
                        distance[adjacent] = distance[actual] + weight;
                        prev[adjacent] = actual;
                        pq.add(new Node(adjacent, distance[adjacent]));
                    }
                }
            }
        }
    }
}

//Retorna en un String la ruta desde s hasta t
//Recibe el nodo destino t
static String path(int t) {
    String r="";
    while(prev[t]!=-1){
        r="-"+t+r;
        t=prev[t];
    }
    if(t!=-1){
        r=t+r;
    }
    return r;
}   

