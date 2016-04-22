Dado un grafo implicito colorea y cuenta el tamaño de las componentes conexas. Normalmente usado en rejillas 2D.

//aka Coloring the connected components

const int tam = 1000; //Máximo tamaño de la rejilla
int dy[] = {1,1,0,-1,-1,-1, 0, 1}; //Estructura auxiliar para los desplazamientos
int dx[] = {0,1,1, 1, 0,-1,-1,-1};
char grid[tam][tam]; //Matriz de caracteres
int X, Y; //Tamaño de la matriz

/*Este método debe ser llamado con las coordenadas x, y donde se inicia el 
recorrido. c1 es el color que estoy buscando, c2 el color con el que se va 
a pintar. Retorna el tamaño de la componente conexa*/
int floodfill(int y, int x, char c1, char c2) { 
	if (y < 0 || y >= Y || x < 0 || x >= X) return 0;
	
	if (grid[y][x] != c1) return 0; // base case
	
	int ans = 1; 
	grid[y][x] = c2; // se cambia el color para prevenir ciclos
	
	for (int i = 0; i < 8; i++)
		ans += floodfill(y + dy[i], x + dx[i], c1, c2);
	
	return ans;
}
