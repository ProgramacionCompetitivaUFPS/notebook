Estructura y métodos para realizar FFT

typedef long double lf;
const lf eps = 1e-8, pi = acos(-1);

/* COMPLEX NUMBERS */
struct pt {
    lf a, b;
    pt() {}
    pt(lf a, lf b) : a(a), b(b) {}
    pt(lf a) : a(a), b(0) {}
    pt operator + (const pt &x) const { return (pt){ a + x.a, b + x.b }; }
    pt operator - (const pt &x) const { return (pt){ a - x.a, b - x.b }; }
    pt operator * (const pt &x) const { return (pt){ a * x.a - b * x.b, a * x.b + b * x.a }; }
};
 
const int MAX = 262144; // Potencia de 2 superior al polinomio c máximo ( 10^5 + 10^5)
pt a[MAX], b[MAX]; //Polinomio a, y b a operarse
 
void rev( pt *a, int n ){
    int i, j, k;
    for( i = 1, j = n >> 1; i < n - 1; i++ ) {
        if( i < j ) swap( a[i], a[j] );
        for( k = n >> 1; j >= k; j -= k, k >>= 1 );
        j += k;
    }
}
 
/* Discrete Fourier Transform */
void dft( pt *a, int n, int flag = 1 ) {
    rev( a, n );
 
    int m, k, j;
    for( m = 2; m <= n; m <<= 1) {
        pt wm = (pt){ cos( flag * 2 * pi / m ), sin( flag * 2 * pi / m ) };
        for( k = 0; k < n; k += m ) {
            pt w = (pt){ 1.0, 0.0 };
            for( j = k; j < k + (m>>1); j++, w = w * wm ) {
                pt u = a[j], v = a[j+(m>>1)] * w;
                a[j] = u + v;
                a[j + (m>>1)] = u - v;
            }
        }
    }
}
 
/* n must be a power of 2 and it is the size of resultant polynomial
 values must be in real part of pt */
void mul( pt *a, pt *b, int n ) {
	int i, x;
    dft( a, n ); dft( b, n );
    for( i = 0; i < n; i++ ) a[i] = a[i] * b[i];
    dft( a, n, -1 );
    for( i = 0; i < n; i++) a[i].a = abs(round(a[i].a/n));
}
 
void init( int n ){
	int i, j;
 
	// Creando los polinomios
	for( i = 0, i < s.size(); i++, j-- ){
		a[i] = pt( 1.0, 0.0 );
	}
 
	// Se completan con 0 los polinomios al tamaño n.
	for( i = s.size() ; i < n; i++ ){
		a[i] = pt( 0.0, 0.0 );
	}
}
 
int get_size(int sz1, int sz2) {
    int n = 1;
    while( n <= sz1 + sz2 ) n <<= 1;
    return n;
}
 