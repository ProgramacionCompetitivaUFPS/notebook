Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento,
si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos disyuntos en un uno.

static int MAX = 100005;
    
    class Dsu{
        
        int dsu[] = new int[MAX];
        int size[] = new int[MAX];
        int numsets;
        
        
        Dsu(int n){
            for(int i = 0; i <= n; i++){
                dsu[i] = i;
                size[i] = 1;
            }
            numsets = n;
        }
        
        int find(int u){
            return (dsu[u] == u) ? u : (dsu[u] = find(dsu[u]));
        }
        
        void union(int a,int b){
            a = find(a);
            b = find(b);
            if(a == b)return;
            if(size[a] > size[b]){
                int c = a;
                a = b;
                b = c;
            }
            dsu[a] = b;
            size[b] += size[a];
            numsets--;
        }
        
        int sizeOf(int i) {
            return size[find(i)]; 
        }
        
    }
