Estructura Edge con su comparador. Usada en algoritmos como Kruskal y Puentes e Itmos.

struct Edge{

  int source, dest, weight;

  bool operator != (const Edge& rhs) const{
    if(rhs.source != source || rhs.dest != dest || rhs.weight != weight){
      return true;
    }
    return false;
  }

};

/* Comparador de Edges */
int cmp(const void* a, const void* b){   
  struct Edge* a1 = (struct Edge*)a;
  struct Edge* b1 = (struct Edge*)b;
  return a1->weight > b1->weight;
}