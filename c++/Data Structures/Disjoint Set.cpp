Estructura de datos para modelar una colección de conjuntos disyuntos. Permite determinar de manera eficiente a que conjunto pertenece un elemento, si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos disyuntos en un conjunto mayor.

const int MAX = 10001; //Cantidad máxima de conjuntos disyuntos
int parent[MAX]; //estructura de DS
int size[MAX]; //Estructura para almacenar el tamaño de los conjuntos.
int cantSets; //Cantidad de conjuntos disyuntos existentes

/* Recibe la cantidad de conjuntos disyuntos iniciales */
void init( int n ){
    cantSets = n;
    for( int i = 0; i <= n; i++ ){
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int i){
  parent[i] = ( parent[i] == i ) ? i : find(parent[i]);
  return parent[i];
}

void unionFind(int x, int y){
  x = find(x);
  y = find(y);

  if( x != y ){
      cantSets--;
      parent[x] = y;
      size[y] += size[x];
  }
}

int sizeOfSet( int i ){
    return size[ find(i) ];
}