static class Node implements Comparable<Node> {
	public int adjacent;
    public int cost;
 
	public Node(int ady, int c) {
	    this.adjacent = ady;
	    this.cost = c;
    }
 
	@Override
	public int compareTo(Node o) {
	    if (this.cost >= o.cost)  return 1;
        else    return -1;
	}
} 