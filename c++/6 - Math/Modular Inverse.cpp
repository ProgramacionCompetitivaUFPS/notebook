El inverso multiplicativo modular de a % m es un entero b tal que (a*b) % m = 1. Este existe siempre y cuando a y m sean coprimos (gcd(a, m) = 1).
El inverso modular de a se utiliza para calcular (n/a) % m como (n*b) % m.

* Se puede calcular usando el algoritmo de Euclides extendido. Agregar Extended Euclides.

// O(log(max(a, m)))
int invmod(int a, int m) {
    int d = euclid(a, m);
    if (d > 1) return -1;
    return (x % m + m) % m;
}

* Si m es un numero primo, se puede calcular aplicando el pequeño teorema de Fermat. Agregar Modular Exponentiation.

// O(log(m))
int invmod(int a, int m) {
    return expmod(a, m-2, m);
}

* Calcular el inverso modulo m para todos los numeros menores o iguales a MX

const int MX = 1e6;
ll inv[MX+1];
// O(MX)
void invmod(ll m) {
    inv[1] = 1;
    for (int i = 2; i <= MX; i++) 
        inv[i] = m - (m/i) * inv[m%i] % m;
}
