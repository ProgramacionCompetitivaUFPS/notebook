Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos disyuntos en un uno.

static int MAX = 10001; //Cantidad maxima de conjuntos disyuntos
static int dsu[] = new int[MAX]; //Almacena al representante de cada conjunto
static int size[] = new int[MAX]; //Almacena eltamaño de cada conjunto
static int numSets; //Cantidad de conjuntos disyuntos existentes

/* Recibe la cantidad de conjuntos disyuntos iniciales */
static void init(int n) {
	numSets = n;
	for(int i = 0; i < n; i++) {
		dsu[i] = i; size[i] = 1;
	}
}

static int find(int i) {
	return (dsu[i] == i) ? i : (dsu[i] = find(dsu[i]));
}

static void unite(int a, int b) {
	a = find(a); b = find(b);
	if(a == b) return;
	if (size[a] > size[b]){int c=a; a=b; b=c;}
	dsu[a] = b;
	size[b] += size[a];
	numSets--;
}

static int sizeOf(int i) { return size[find(i)]; }
	
