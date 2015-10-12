Guarda en el array Catalan Numbers los numeros de Catalan hasta MAX.

const int MAX = 30;
long long catalanNumbers[MAX+1];

void catalan(){
	catalanNumbers[0] = 1;
	for(int i = 1; i <= MAX; i++){
		catalanNumbers[i] = (long long)(catalanNumbers[i-1]*((double)(2*((2 * i)- 1))/(i + 1)));
	}
}
