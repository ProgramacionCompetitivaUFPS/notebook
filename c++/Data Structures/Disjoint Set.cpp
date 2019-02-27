Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos en un uno.

const int MAX = 10001; //Cantidad maxima de conjuntos disyuntos
int dsu[MAX]; //Almacena el indice del lider de cada conjunto
int size[MAX]; //Almacenar el tamano de los conjuntos
int numSets; //Cantidad de conjuntos disyuntos existentes

/** Recibe la cantidad de conjuntos disyuntos iniciales **/
void init(int n) {
	contSets = n;
	for(int i = 0; i < n; i++) {
		dsu[i] = i; size[i] = 1;
	}
}

int find(int i) {
	return (dsu[i] == i) ? i : (dsu[i] = find(dsu[i]));
}

void unite(int a, int b) {
	a = find(a); b = find(b);
	if(a == b) return;
	if (size[a] > size[b]) swap(a, b);
	dsu[a] = b;
	size[b] += size[a];
	numSets--;
}

int sizeOf(int i) { return size[find(i)]; }
