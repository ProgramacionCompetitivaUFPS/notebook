#include <bits/stdc++.h>
using namespace std;

int v, e; //v = cantidad de nodos, e = cantidad de aristas
const int MAX=100005; //Cantidad máxima de nodos del grafo
vector<int> ady[MAX]; //lista de Adyacencia del grafo

void init() {
    int i;
    for( i = 0; i < v; i++ ) {
        ady[i].clear();
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

        ady[ origen ].push_back( destino );
        ady[ destino ].push_back( origen );
        e--;
    }

    return 0;
}
