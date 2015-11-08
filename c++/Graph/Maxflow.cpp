

vector<int> adyNetwork [105]; 
int capacity [105] [105]; //Capacidad de aristas de la red
int flow [105] [105]; //Flujo de cada arista
int anterior [105];

void connect(int i, int j, int cap){
    adyNetwork[i].push_back(j);
    adyNetwork[j].push_back(i);
    capacity[i][j]+=cap;
    //Si el grafo es dirigido no hacer esta linea
    //capacity[j][i]+=cap;
}

int maxflow(int s, int t, int n){ //s=fuente, t=sumidero, n=numero de nodos
    int i, j, maxFlow, u, v, extra, start, end;
    for(i=0; i<=n; i++){
        for(j=0; j<=n; j++){
            flow[i][j]=0;
        }
    }

    maxFlow=0;

    while(true){
        for(i=0; i<=n; i++) anterior[i]=-1;

        queue<int> q;
        q.push(s);
        anterior[s]=-2;

        while(q.size()>0){
            u=q.front();
            q.pop();
            if(u==t) break;
            for(j=0; j<adyNetwork[u].size(); j++){
                
                v=adyNetwork[u][j];
                if(anterior[v]==-1  && capacity[u][v] - flow[u][v]>0){
                    q.push(v);
                    anterior[v]=u;
                }
            }
        }
        if(anterior[t]==-1)break;

        extra=1<<30;
        end=t;
        while(end!=s){
            start=anterior[end];
            extra=min(extra, capacity[start][end]-flow[start][end]);
            end=start;
        }

        end=t;
        while(end!=s){
            start=anterior[end];
            flow[start][end]+=extra;
            flow[end][start]= -flow[start][end];
            end=start;
        }

        maxFlow+=extra;
    }

    return maxFlow;
}

int main(){
    //Para cada arista
    connect(s,d,f);  //origen, destino, flujo
}

