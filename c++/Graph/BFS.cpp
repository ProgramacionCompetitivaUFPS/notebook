Algoritmo de búsqueda en anchura en grafos, recibe un nodo inicial s y visita todos los nodos alcanzables desde s. BFS también halla la distancia más corta entre el nodo inicial s y los demás nodos si todas las aristas tienen peso 1.

int v, e; //vertices, arcos
const int MAX=100005; //Cantidad máxima de nodos del grafo
vector<int> ady[MAX]; //lista de Adyacencia del grafo
long long dist[MAX]; //Estructura auxiliar para almacenar la distancia a cada nodo.

/*Debe llamarse al iniciar cada caso de prueba luego de haber leido v
Limpia todas las estructuras de datos.*/
static void init() {
  for (int j = 0; j <= v; j++) {
    dist[j] = -1;
    ady[j].clear();
  }
}

/*Este método se llama con el indice del nodo desde el que se desea comenzar
el recorrido.*/
static void bfs(int s){
  queue<int> q;
  q.push(s); //Inserto el nodo inicial
  dist[s]=0;
  int actual, i, next;
       
  while(q.size()>0){
    actual=q.front();
    q.pop();
    for(i=0; i<ady[actual].size(); i++){
      next=ady[actual][i];
      if(dist[next]==-1){
        dist[next]=dist[actual]+1;
        q.push(next);
      }
    }
  }

}
