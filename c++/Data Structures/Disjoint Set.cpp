Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos disyuntos en un uno.

const int MAX = 10001; //Cantidad maxima de conjuntos disyuntos
int parent[MAX]; //estructura de DS
int size[MAX]; //Estructura para almacenar el tamano de los conjuntos
int rnk[MAX]; //Estructura para optimizacion: compresion de ruta
int cantSets; //Cantidad de conjuntos disyuntos existentes

/* Recibe la cantidad de conjuntos disyuntos iniciales */
void init(int n) {
	cantSets = n;
	for(int i = 0; i < n; i++) {
		parent[i] = i; size[i] = 1; rnk[i] = 0;
	}
}

int find(int i) {
	return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
}

void unionSet(int x, int y) {
	x = find(x); y = find(y);
	if(x != y) {
		cantSets--;
		if (rnk[x] > rnk[y]) swap(x, y);
		parent[x] = y;
		size[y] += size[x];
		rnk[y] += (rnk[x] == rnk[y]);
	}
}

int sizeOfSet(int i) { return size[find(i)]; }
