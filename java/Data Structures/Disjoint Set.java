Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos disyuntos en un uno.

static int MAX = 10001; //Cantidad maxima de conjuntos disyuntos
static int dsu[] = new int[MAX]; //Estructura de DS
static int size[] = new int[MAX]; //Estructura para almacenar el tamano de los conjuntos
static int rnk[] = new int[MAX]; //Estructura para optimizacion: compresion de ruta
static int cantSets; //Cantidad de conjuntos disyuntos existentes

/* Recibe la cantidad de conjuntos disyuntos iniciales */
static void init(int n) {
	cantSets = n;
	for(int i = 0; i < n; i++) {
		dsu[i] = i; size[i] = 1; rnk[i] = 0;
	}
}

static int find(int i) {
	return (dsu[i] == i) ? i : (dsu[i] = find(dsu[i]));
}

static void union(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return;
	cantSets--;
	if (rnk[x] > rnk[y]) { int z=x;x=y;y=z; };
	dsu[x] = y;
	size[y] += size[x];
	rnk[y] += (rnk[x] == rnk[y] ? 1 : 0);
}

static int sizeOf(int i) { return size[find(i)]; }
