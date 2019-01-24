Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos disyuntos en un uno.

const int MAX = 10001; //Cantidad maxima de conjuntos disyuntos
int dsu[MAX]; //Estructura de DS
int size[MAX]; //Estructura para almacenar el tamano de los conjuntos
int rnk[MAX]; //Estructura para optimizacion: compresion de ruta
int cantSets; //Cantidad de conjuntos disyuntos existentes

/* Recibe la cantidad de conjuntos disyuntos iniciales */
void init(int n) {
	cantSets = n;
	for(int i = 0; i < n; i++) {
		dsu[i] = i; size[i] = 1; rnk[i] = 0;
	}
}

int _find(int i) {
	return (dsu[i] == i) ? i : (dsu[i] = _find(dsu[i]));
}

void _union(int x, int y) {
	x = _find(x); y = _find(y);
	if(x == y) return;
	cantSets--;
	if (rnk[x] > rnk[y]) swap(x, y);
	dsu[x] = y;
	size[y] += size[x];
	rnk[y] += (rnk[x] == rnk[y]);
}

int _sizeOf(int i) { return size[_find(i)]; }
