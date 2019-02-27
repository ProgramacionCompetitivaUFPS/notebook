Guarda en el array catalan[] los numeros de Catalan hasta MAX.

const int MAX = 30;
long long catalan[MAX+1];

void catalanNumbers() {
    catalan[0] = 1;
    for(int i = 1; i <= MAX; i++){
        catalan[i] = (long long)(catalan[i-1]*((double)(2*((2 * i)- 1))/(i + 1)));
    }
}
