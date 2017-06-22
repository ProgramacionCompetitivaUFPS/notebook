Calculo del mínimo común múltiplo usando el máximo común divisor. REQUIERE mcd(a,b)

int mcm (int a, int b) {
	return a * b / mcd(a, b);
}
