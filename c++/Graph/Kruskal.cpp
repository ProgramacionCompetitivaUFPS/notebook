Algoritmo para hallar el arbol cobertor mínimo de un grafo  no dirigido y conexo. Utiliza la técnica de Union-Find(Conjuntos disjuntos) para detectar que aristas generan ciclos.
Requiere de la struct Edge.

int v, e; //v = nodos, e = arcos
const int MAX = 10001; //Cantidad máxima de NODOS
const int MAXE = 10001; //Cantidad máxima de ARCOS
int parent[MAX]; //estructura de DS
Edge edges[MAXE]; //Lista de arcos del grafo
Edge answer[MAX]; //Lista de arcos del arbol cobertor mínimo

/*        Métodos Disjoint Set          */
int find(int i){
  parent[i] = ( parent[i] == i ) ? i : find(parent[i]);
  return parent[i];
}

void unionFind(int x, int y){
  parent[ find(x) ] = find(y);
}

/*El arbol cobertor mínimo del grafo queda almacenado en el 
vector de arcos answer*/
void kruskall(){
  Edge actual;
  int aux = 0;
  int i = 0;
  int x, y;
  qsort( edges, e, sizeof(edges[0]), cmp);

  while(aux < v-1 && i < edges.size() ){
    actual = edges[i];
    x = find( actual.source );
    y = find( actual.dest );

    if(x != y){
      answer[aux] = actual;
      aux++;
      unionFind(x, y);
    }
    i++;
  }
}

int main(){
  int s, d, w;
  //Los arcos se inicializan así
  edges[i].source = s;
  edges[i].dest = d;
  edges[i].weight = w;

  kruskall();
}