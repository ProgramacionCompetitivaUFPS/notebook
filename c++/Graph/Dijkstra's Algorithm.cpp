Algoritmo que dado un grafo con pesos no negativos halla la ruta mínima entre un nodo inicial s y todos los demás nodos.

int v,e;
vector<Node> ady[100001];
int marked[100001];
long long distance[100001];
int prev[100001];

class cmp
{
public:
    bool operator()(Node n1,Node n2)
    {
      if(n1.second>n2.second)
      return true;
      else
      return false;
    }
};

void init(){
    long long max=LLONG_MAX;
    for(int j=0; j<=v; j++){
        ady[j].clear();
        marked[j]=0;
        prev[j]=-1;
        distance[j]=max;
    }
}

void dijkstra(int s){
    priority_queue< Node , vector<Node> , cmp > pq;
    pq.push(Node(s, 0));//se inserta a la cola el nodo Inicial.
    distance[s]=0;
    int actual, j, adjacent;
    long long weight;

    while(!pq.empty()){
        actual=pq.top().first;
        pq.pop();
        if(marked[actual]==0){
            marked[actual]=1;
            for(j=0; j<ady[actual].size(); j++){
                adjacent=ady[actual][j].first;
                weight=ady[actual][j].second;
                if(marked[adjacent]==0){
                    if(distance[adjacent]>distance[actual]+weight){
                         distance[adjacent]=distance[actual]+weight;
                         prev[adjacent]=actual;
                         pq.push(Node(adjacent, distance[adjacent]));
                     }
                }
            }
        }
    }
}
