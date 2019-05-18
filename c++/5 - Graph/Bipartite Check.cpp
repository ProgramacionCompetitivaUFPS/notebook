Algoritmo para la detección de grafos bipartitos. Modificación de BFS.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

int v, e; //vertices, arcos
const int MAX=100005; //Cantidad máxima de nodos del grafo
vector<int> ady[MAX]; //lista de Adyacencia del grafo
int color[MAX]; //Estructura auxiliar para almacenar la distancia a cada nodo.
bool bipartite;

/*Este método se llama con el indice del nodo desde el que se desea comenzar
el recorrido.*/
void bfs(int s){
  queue<int> q;
  q.push(s);
  color[s] = 0;
  int actual, i, next;
       
  while( q.size() > 0 ){
    actual = q.front();
    q.pop();

    for( i = 0; i < ady[actual].size(); i++){
      next = ady[actual][i];
      if( color[next] == -1 ){
        color[next] = 1 - color[actual];
        q.push(next);
      }else if( color[next] == color[actual] ){
        bipartite = false;
        return;
      }
    }
  }

}
