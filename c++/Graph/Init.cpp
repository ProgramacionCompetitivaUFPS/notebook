Método para la limpieza de TODAS las estructuras de datos utilizadas en TODOS los algoritmos de grafos.
Copiar solo las necesarias, de acuerdo al algoritmo que se este utilizando.

/*Debe llamarse al iniciar cada caso de prueba luego de haber leido la cantidad de nodos v
Limpia todas las estructuras de datos.*/
void init() {
    long long max = LLONG_MAX;
    rta = 0; //Prim
    cont = dfsRoot = rootChildren = 0; //Puentes
    bridges.clear(); //Puentes
    topoSort.clear(); //Topological Sort

    for( int j = 0; j <= v; j++ ) {
        dist[j] = -1; //Distancia a cada nodo (BFS)
        dist[j] = max; //Distancia a cada nodo (Dijkstra)
        ady[j].clear(); //Lista de Adyacencia
        marked[j] = 0; //Estructura auxiliar para marcar los nodos ya visitados
        previous[j] = -1;  //Estructura auxiliar para almacenar las rutas
        parent[j] = j; //Estructura auxiliar para DS
        dfs_num[j] = -1;
        dfs_low[j] = 0;
        itsmos[j] = 0;
    }
}
