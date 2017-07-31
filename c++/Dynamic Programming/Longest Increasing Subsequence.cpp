Halla la longitud de la subsecuencia creciente mas larga. MAX debe definirse en el tamaño  limite del array, n es el tamaño del array. Si se admiten valores repetidos, cambiar el < de I[mid] <= values[i] por <=

const int inf = 2000000000;
const int MAX = 100000; //Máximo número de valores en la secuencia
int n; //Tamaño de la secuencia
int values[MAX + 5]; //Secuencia de valores
int L[MAX + 5]; 
int I[MAX + 5]; 

int lis() { 
 	int i, low, high, mid;
 	I[0] = -inf; 
 	for (i = 1; i <= n; i++) I[i] = inf;
 	int ans = 0;
 	for(i = 0; i < n; i++) {
 		low = mid = 0;
 		high = ans;
 		while(low <= high) {
 			mid = (low + high) / 2;
 			if(I[mid] < values[i]) low = mid + 1;
 			else high = mid - 1;
 		} 
 		I[low] = values[i];
 		if(ans < low) ans = low;
	}
 	return ans;
}
