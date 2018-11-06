#include <bits/stdc++.h>
using namespace std;

int v, e; //v = cantidad de nodos, e = cantidad de aristas
const int MAX=1000; //Cantidad Máxima de Nodos
int ady[MAX][MAX];

void init() {
    int i, j;
    for( i = 0; i < v; i++ ) {
        for( j = 0; j < v; j++ ) {
            ady[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int origen, destino;

    //Al iniciar cada caso de prueba
    cin>>v>>e;
    init();

    while( e > 0 ) {
        cin>>origen>>destino;

        ady[ origen ][ destino ] = 1;
        ady[ destino ][ origen ] = 1;
        e--;
    }

    return 0;
}
