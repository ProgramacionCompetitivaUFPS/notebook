Calcula el Periodo de Pisano de m, que es el periodo con el cual se repite la Sucesión de Fibonacci modulo m.
IMPORTANTE: Si m es primo el algoritmo funciona (considerable) para m < 10^6. Debe agregarse Modular Exponentiation (sin el modulo) y Lowest Common Multiple (para long long).

long long period(long long m) {
    long long a = 0, b = 1, c, pp = 0;
    do {
        c = (a + b) % m;
        a = b; b = c; pp++;
    } while (a != 0 || b != 1);
    return pp;
}

long long pisanoPrime(long long p, long long e) {
    return modpow(p, e-1) * period(p);
}

long long pisanoPeriod(long long m) {
    long long pp = 1;
    for (long long p = 2; p*p <= m; p++) {
    	if (m % p == 0) {
	    	long long e = 0;
	        while (m % p == 0) e++, m /= p;
	        pp = lcm(pp, pisanoPrime(p, e));
    	}
    }
    if (m > 1) pp = lcm(pp, period(m));
    return pp;
}
