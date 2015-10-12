Guarda en el array Catalan Numbers los numeros de Catalan hasta MAX.

static int MAX = 30;
static long catalanNumbers[] = new long[MAX+1];

static void catalan(){
	catalanNumbers[0] = 1;
	for(int i = 1; i <= MAX; i++){
		catalanNumbers[i] = (long)(catalanNumbers[i-1]*((double)(2*((2 * i)- 1))/(i + 1)));
	}
}
