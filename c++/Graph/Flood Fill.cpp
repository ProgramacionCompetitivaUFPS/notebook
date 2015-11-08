Dado un grafo implicito colorea y cuenta el tamaño de las componentes conexas. Normalmente usado en rejillas 2D.

//aka Coloring the connected components

int dy[] = {1,1,0,-1,-1,-1, 0, 1}; 
int dx[] = {0,1,1, 1, 0,-1,-1,-1};
char grid[tam][tam];
int X, Y;

int floodfill(int y, int x, char c1, char c2) { 
	if (y < 0 || y >= Y || x < 0 || x >= X) return 0;
	
	if (grid[y][x] != c1) return 0; // base case
	
	int ans = 1; 
	grid[y][x] = c2; // se cambia el color para prevenir ciclos
	
	for (int i = 0; i < 8; i++)
		ans += floodfill(y + dy[i], x + dx[i], c1, c2);
	
	return ans;
}
