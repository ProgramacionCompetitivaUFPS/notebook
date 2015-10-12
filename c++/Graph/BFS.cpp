Algoritmo de búsqueda en anchura en grafos, recibe un nodo inicial s y visita todos los nodos alcanzables desde s. BFS también halla la distancia más corta entre el nodo inicial s y los demás nodos si todas las aristas tienen peso 1.

int v, e; //vertices, arcos
int MAX=100005; 
vector<int> ady[MAX]; //lista de Adyacencia
long long distance[MAX];

static void init() {
    for (int j = 0; j <= v; j++) {
        distance[j] = -1;
        ady[j].clear();
    }
}

static void bfs(int s){
    queue<int> q;
    q.push(s); //Inserto el nodo inicial
    distance[s]=0;
    int actual, i, next;
        
    while(q.size()>0){
        actual=q.front();
        q.pop();
        for(i=0; i<ady[actual].size(); i++){
            next=ady[actual][i];
            if(distance[next]==-1){
                distance[next]=distance[actual]+1;
                q.push(next);
            }
        }
    }
}
