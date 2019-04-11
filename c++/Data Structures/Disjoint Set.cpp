Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos en un uno.

const int MAX = 100005;

struct Dsu{
    int dsu[MAX];
    int size[MAX];
    int numsets;

    Dsu(int n){
        for(int i = 0; i <= n; i++){
            dsu[i] = i;
            size[i] = 1;
        }
        numsets = n;
    }

    int find(int u){
        return (dsu[u] == u) ? u : (dsu[u] == find(dsu[u]));
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b)return;
        if(size[a] > size[b])swap(a,b);
        dsu[a] = b;
        size[b] += size[a];
        numsets--;
    }

    int sizeOf(int u){
        return size[find(u)];
    }

};
