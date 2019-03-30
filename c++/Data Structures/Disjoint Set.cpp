Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos en un uno.

const int MAX = 10001; //Cantidad maxima de conjuntos disyuntos
int dsu[MAX]; //Almacena el indice del lider de cada conjunto
int size[MAX]; //Almacenar el tamano de los conjuntos
int numSets; //Cantidad de conjuntos disyuntos existentes

/** Recibe la cantidad de conjuntos disyuntos iniciales **/
void init(int n) {
	numSets = n;
	for(int i = 0; i < n; i++) {
		dsu[i] = i; size[i] = 1;
	}
}

int find(int u) {
	return (dsu[u] == u) ? u : (dsu[u] = find(dsu[u]));
}

void unite(int u, int v) {
	u = find(u); v = find(v);
	if(u == v) return;
	if (size[u] > size[v]) swap(u, v);
	dsu[u] = v;
	size[v] += size[u];
	numSets--;
}

int sizeOf(int u) { return size[find(u)]; }
