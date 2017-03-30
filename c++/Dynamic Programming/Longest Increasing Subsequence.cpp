Halla la longitud de la subsecuencia creciente mas larga. MAX debe definirse en el tamaño  limite del array, n es el tamaño del array. Puede aplicarse también sobre strings, cambiando el parametro int s[] por string s. Si debe ser estrictamente creciente, cambiar el <= de s[j] <= s[i] por <

const int MAX = 1005;
int memo[MAX];

int longestIncreasingSubsequence(int s[], int n){
	memo[0] = 1;
	int output = 1;
	for (int i = 1; i < n; i++){
		memo[i] = 1;
		for (int j = 0; j < i; j++){
			if (s[j] <= s[i] && memo[i] < memo[j] + 1){
				memo[i] =  memo[j] + 1;
			} 
		}
		if(memo[i] > output){
			output = memo[i];
		}
	}
	return output;
}
