Algoritmo para hallar el arbol cobertor mínimo de un grafo  no dirigido y conexo. Utiliza la técnica de Union-Find(Conjuntos disjuntos) para detectar que aristas generan ciclos.
Para hallar los 2 arboles cobertores minimos, se debe ejecutar el algoritmo v-1 veces, en cada una de ellas dscartar una de las aristas previamente elegidas en el arbol.

struct Edge{

  int source, dest, weight;

  bool operator != (const Edge& rhs) const{
    if(rhs.source != source || rhs.dest != dest || rhs.weight != weight){
      return true;
    }
    return false;
  }

};

int v, e; //v = nodos, e = arcos
const int MAX = 10001; //Cantidad máxima de nodos
int parent[MAX]; //estructura de DS
int r[MAX]; //estructura de la implementación de DS (rank)
Edge edges[MAX]; //Lista de arcos del grafo
Edge answer[MAX]; //Lista de arcos del arbol cobertor mínimo

/*Debe llamarse al iniciar cada caso de prueba para limpiar las estructuras. 
Debe haberse leido v antes de hacer el llamado. */
void init(){
  for(int i = 0; i < v; i++){
    parent[i] = i;
    r[i] = 0;
  }
}

int cmp(const void* a, const void* b){   
  struct Edge* a1 = (struct Edge*)a;
  struct Edge* b1 = (struct Edge*)b;
  return a1->weight > b1->weight;
}

/*        Métodos Disjoint Set          */
int find(int i){
  if( parent[i] != i ){
    parent[i] = find(parent[i]);
  }
  return parent[i];
}

void unionFind(int x, int y){
  int xroot = find(x);
  int yroot = find(y);
 
  // Attach smaller r tree under root of high r tree
  if (r[xroot] < r[yroot])
    parent[xroot] = yroot;
  else if (r[xroot] > r[yroot])
    parent[yroot] = xroot;
  else{
    parent[yroot] = xroot;
    r[xroot]++;
  }

}

/*       FIN: Métodos Disjoint Set         */

/*El arbol cobertor mínimo del grafo queda almacenado en el 
vector de arcos answer*/
void kruskall(){
  Edge actual;
  int aux = 0;
  int i = 0;
  int x, y;
  qsort(edges, e, sizeof(edges[0]), cmp);

  while(aux < v-1){
    actual = edges[i];
    x = find(actual.source);
    y = find(actual.dest);

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