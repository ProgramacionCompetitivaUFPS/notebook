Algoritmo para la detección de grafos bipartitos. Modificación de BFS.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

static int v, e; //vertices, arcos
static int MAX=100005; 
static ArrayList<Integer> ady[] = new ArrayList[MAX]; //lista de Adyacencia
static long distance[] = new long[MAX];
static int color[] = new int[MAX];
static boolean bipartite;

//Recibe el nodo inicial s
static void bfs(int s){
    Queue<Integer> q = new LinkedList<Integer>();
    q.add(s); 
    color[s] = 0;
    int actual, i, next;
    bipartite=true;

    while( !q.isEmpty() && bipartite ){
        actual = q.poll();
        for( i = 0; i < ady[actual].size(); i++){
            next = ady[actual].get(i);
            if( color[next] == -1 ){
                color[next] = 1 - color[actual];
                q.add(next);
            }else if( color[next] == color[actual] ){
                bipartite = false;
                return;
            }
        }
    }
}