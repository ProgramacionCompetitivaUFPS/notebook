Para cada posición i del array totient calcula el número de enteros positivos menores o iguales a n que son coprimos con n (Coprimos: MCD=1)

const int MAX = 100;
int totient[MAX+1]; 
bitset<MAX+1> marked;

void totientSieve() {
    marked[1] = 1;
    for (int i = 0; i <= MAX; i++) totient[i] = i;
    for (int i = 2; i <= MAX; i++) if (!marked[i]) {
        for (int j = i; j <= MAX ; j += i){
            totient[j] -= totient[j] / i;
            marked[j] = 1;
        }
        marked[i] = 0;
    }
}