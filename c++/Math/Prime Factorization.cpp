Guarda en primeFactors la lista de factores primos del value de menor a mayor. IMPORTANTE: Debe ejecutarse primero la criba de Eratostenes.  La criba debe existir al menos hasta la raiz cuadrada de value (se  recomienda dejar un poco de excedente).

#include <vector>

vector <long long> primeFactors;

void calculatePrimeFactors(long long value){
	primeFactors.clear();
	long long temp = value;
	int factor;
	for (int i = 0; (long long)primes[i] * primes[i] <= value; ++i){
		factor = primes[i];
		while (temp % factor == 0){
			primeFactors.push_back(factor);
			temp /= factor;
		}
	}
	if (temp != 1) {
		primeFactors.push_back(temp);
	}
}
