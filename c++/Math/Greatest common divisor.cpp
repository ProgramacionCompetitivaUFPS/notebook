Calcula el máximo común divisor entre a y b mediante el algoritmo de Euclides

int mcd (int a, int b) {
	while (b != 0){
		a %= b;
		swap(a, b);
	}
	return a;
}