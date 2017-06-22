Guarda en primeFactors la lista de factores primos del value de menor a mayor. IMPORTANTE: Debe ejecutarse primero la criba de Eratostenes.  La criba debe existir al menos hasta la raiz cuadrada de value (se  recomienda dejar un poco de excedente).

import java.util.ArrayList;

static ArrayList<Long> primeFactors = new ArrayList<Long>();

static void calculatePrimeFactors(long value){
	primeFactors.clear();
	long temp = value;
	int factor;
	for (int i = 0; (long)primes.get(i) * primes.get(i) <= value; ++i){
		factor = primes.get(i);
		while (temp % factor == 0){
			primeFactors.add((long)factor);
			temp /= factor;
		}
	}
	if (temp != 1) primeFactors.add(temp);
}
