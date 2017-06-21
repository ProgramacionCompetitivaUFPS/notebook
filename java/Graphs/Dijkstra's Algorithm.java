ALgoritmo que dado un grafo con pesos no negativos halla la ruta mínima entre un nodo inicial s y todos los demás nodos.

import java.util.ArrayList;
import java.util.PriorityQueue;


static int v, e; //v = cantidad de nodos, e = cantidad de aristas
static int MAX=100005; //Cantidad Máxima de Nodos
static ArrayList<Node> ady[] = new ArrayList[MAX]; //Lista de Adyacencia del grafo
static int marked[] = new int[MAX]; //Estructura auxiliar para marcar los nodos visitados
static long distance[] = new long[MAX]; //Estructura auxiliar para llevar las distancias a cada nodo
static int prev[] = new int[MAX]; //Estructura auxiliar para almacenar las rutas

//Método para limpiar los valores de las estructuras.
//Llamarlo siempre antes de utilizar el método dijkstra()
static void init() {
    long max = Long.MAX_VALUE;

    for (int j = 0; j <= v; j++) {
        marked[j] = 0;
        prev[j] = -1;
        distance[j] = max;
        ady[j] = new ArrayList<Node>();
    }
}

    
//Recibe el nodo inicial s
static void dijkstra(int s) {
    PriorityQueue<Node> pq=new PriorityQueue<Node>();
    pq.add(new Node(s, 0));//se inserta a la cola el nodo Inicial.
    distance[s] = 0;
    int actual, j, adjacent;
    long weight;
    Node x;

    while (pq.size() > 0) {
        actual = pq.peek().adjacent;
        pq.poll();
        if (marked[actual] == 0) {
            marked[actual] = 1;
            for (j = 0; j < ady[actual].size(); j++) {
                adjacent = ady[actual].get(j).adjacent;
                weight = ady[actual].get(j).cost;
                if (marked[adjacent] == 0) {
                    if (distance[adjacent] > distance[actual] + weight) {
                        distance[adjacent] = distance[actual] + weight;
                        prev[adjacent] = actual;
                        pq.add(new Node(adjacent, distance[adjacent]));
                    }
                }
            }
        }
    }
}

//Retorna en un String la ruta desde s hasta t
//Recibe el nodo destino t
static String path(int t) {
    String r="";
    while(prev[t]!=-1){
        r="-"+t+r;
        t=prev[t];
    }
    if(t!=-1){
        r=t+r;
    }
    return r;
}


static class Node implements Comparable<Node> {

    public int adjacent;
    public long cost;

    public Node(int ady, long c) {
        this.adjacent = ady;
        this.cost = c;
    }

    @Override
    public int compareTo(Node o) {
        if (this.cost >= o.cost) {
            return 1;
        } else {
            return -1;
        }
    }
}    

