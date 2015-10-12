Función totient o indicatriz (φ) de Euler. Para cada posición n del array result retorna el número de enteros positivos menores o iguales a n que son coprimos con n (Coprimos: MCD=1)

#include <string.h>

const int MAX = 100;
int result[MAX]; 

void totient () {
	bool temp[MAX];
	int i,j;
	memset(temp,1,sizeof(temp));
	for(i = 0; i < MAX; i++) {
		result[i] = i;
	}
	for(i = 2; i < MAX; i++){
		if(temp[i]) {
			for(j = i; j < MAX ; j += i){
				temp[j] = false;
				result[j] = result[j] - (result[j]/i) ;
			}
			temp[i] = true ;
		}
	}
}
