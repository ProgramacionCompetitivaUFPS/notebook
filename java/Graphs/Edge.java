/* Arco Simple */
static class Edge{

    public int src, dest;
    
    public Edge(int s, int d) {
        this.src = s;
        this.dest = d;
    }
}

/* Arco con pesos */
static class Edge implements Comparable<Edge> {

    public int src, dest, weight;
    
    public Edge(int s, int d, int w) {
        this.src = s;
        this.dest = d;
        this.weight=w;
    }
    
    @Override
    public int compareTo(Edge o) {
        return this.weight-o.weight;
    }
}