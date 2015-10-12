Calcula el máximo común divisor entre a y b mediante el algoritmo de Euclides

int mcd(int a, int b) {
	int aux;
	while(b!=0){
		a %= b;
		aux = b;
		b = a;
		a = aux;
	}
	return a;
}
