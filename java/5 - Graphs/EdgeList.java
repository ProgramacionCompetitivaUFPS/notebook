import java.util.*;

public class Main{
  
  static int v, e; //v = cantidad de nodos, e = cantidad de aristas
  static ArrayList<Edge> edges;
  
  public static void main( String [] args ){
    int origen, destino;
    Scanner sc = new Scanner( System.in );
    
    //Al iniciar cada caso de prueba
    v = sc.nextInt();
    e = sc.nextInt();
    init();
    
    while( e > 0 ){
      origen = sc.nextInt();
      destino = sc.nextInt();
      edges.add( new Edge(origen, destino) );
      e--;
    }
  }
  
	static void init(){
		edges = new ArrayList<Edge>(); //Kruskal
	}
  
	 /* Arco Simple */
	static class Edge{
	
	  public int src, dest;
	    
	  public Edge(int s, int d) {
	    this.src = s;
	    this.dest = d;
	  }
	}
}
