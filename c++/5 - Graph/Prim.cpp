Algoritmo para hallar el arbol cobertor mínimo de un grafo  no dirigido y conexo. 
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

#define Node pair < int, long long > //(Vertice adyacente, peso)

int v, e; //vertices, arcos
const int MAX = 100005; 
vector < Node > ady[MAX]; 
bool marked[MAX]; 
int rta; 

class cmp {
  public:
    bool operator()(Node n1, Node n2) {
      return (n1.second > n2.second); 
}; 

static void prim() {
  priority_queue < Node, vector < Node > , cmp > pq; 
  int u, w, i, v; 

  marked[0] = true; 
  for (i = 0; i < ady[0].size(); i++) {
    v = ady[0][i].first; 
    if ( ! marked[v]) pq.add(Node(v, ady[u][i].second)); 
	}

	while ( ! pq.empty()) {
		u = pq.top().first; 
		w = pq.top().second; 

		pq.pop(); 

		if ( !marked[u]) {
			rta += w; 
			marked[u] = true; 
      for (i = 0; i < ady[u].size(); i++) {
        v = ady[u][i].first; 
        if ( ! marked[v]) pq.add(Node(v, ady[u][i].second)); 
      }
		}
	}
}