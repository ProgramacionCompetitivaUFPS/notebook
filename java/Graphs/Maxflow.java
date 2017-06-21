Dado un grafo, halla el máximo flujo entre una fuente s y un sumidero t.

static int n; //Cantidad de nodos del grafo
static ArrayList<Integer> adyNetwork[] = new ArrayList[105]; //lista de Adyacencia
static int capacity[][]  = new int[105][105]; //Capacidad de aristas de la red
static int flow[][] = new int[105][105]; //Flujo de cada arista
static int anterior[] = new int[105];

static void connect(int i, int j, int cap){
    adyNetwork[i].add(j);
    adyNetwork[j].add(i);
    capacity[i][j] += cap;
    //Si el grafo es dirigido no hacer esta linea
    //capacity[j][i] += cap;
}

static int maxflow(int s, int t, int n){ //s=fuente, t=sumidero, n=numero de nodos
    int i, j, maxFlow, u, v, extra, start, end;
    for( i = 0; i <= n; i++ ){
        for( j = 0; j <= n; j++ ){
            flow[i][j] = 0;
        }
    }

    maxFlow = 0;

    while( true ){
        for( i = 0; i <= n; i++ ) anterior[i] = -1;

        Queue<Integer> q = new LinkedList<Integer>();
        q.add(s);
        anterior[s] = -2;

        while( !q.isEmpty() ){
            u = q.poll();
            if( u == t ) break;
            for( j = 0; j < adyNetwork[u].size(); j++){
                v = adyNetwork[u].get(j);
                if( anterior[v] == -1  && capacity[u][v] - flow[u][v] > 0 ){
                    q.add(v);
                    anterior[v] = u;
                }
            }
        }
        if( anterior[t] == -1 ) break;

        extra = Integer.MAX_VALUE;
        end = t;
        while( end != s ){
            start = anterior[end];
            extra = Math.min( extra, capacity[start][end]-flow[start][end] );
            end = start;
        }

        end = t;
        while( end != s){
            start = anterior[end];
            flow[start][end] += extra;
            flow[end][start] = -flow[start][end];
            end = start;
        }

        maxFlow += extra;
    }

    return maxFlow;
}

public static void main( String args[] ){
    //Para cada arista
    connect( s, d, f);  //origen, destino, flujo
}

