Método para la limpieza de TODAS las estructuras de datos utilizadas en TODOS los algoritmos de grafos.
Copiar solo las necesarias, de acuerdo al algoritmo que se este utilizando.

/*Debe llamarse al iniciar cada caso de prueba luego de haber leido la cantidad de nodos v
Limpia todas las estructuras de datos.*/
static void init() {
    long max = Long.MAX_VALUE;
    edges = new ArrayList<Edge>(); //Kruskal
    answer = new ArrayList<Edge>(); //Kruskal
    loops = false; //Loop Check
    rta = 0; //Prim
    pq = new PriorityQueue<Node>(); //Prim
    cont = dfsRoot = rootChildren = 0; //Puentes
    bridges = new ArrayList<Edge>(); //Puentes
    cantSCC = 0; //Tarjan
    topoSort = new ArrayList<Integer>(); //Topological Sort
    bipartite = true;

    for (int j = 0; j <= v; j++) {
        distance[j] = -1; //Distancia a cada nodo (BFS)
        distance[j] = max; //Distancia a cada nodo (Dijkstra)
        ady[j] = new ArrayList<Integer>(); //Lista de Adyacencia
        ady[j] = new ArrayList<Node>(); //Lista de Adyacencia (Dijkstra)
        marked[j] = false; //Estructura auxiliar para marcar los nodos ya visitados
        prev[j] = -1; //Estructura auxiliar para almacenar las rutas
        parent[j] = j; //Estructura auxiliar para DS
        dfs_num[j] = -1;
        dfs_low[j] = 0;
        itsmos[j] = false;
        color[j] = -1; //Bipartite Check

        for(j = 0; j < v; j++)  ady[i][j] = Integer.MAX_VALUE; //Warshall
    }
}