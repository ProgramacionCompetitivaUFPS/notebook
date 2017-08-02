import java.util.*;

public class Main{
  
  static int v, e; //v = cantidad de nodos, e = cantidad de aristas
  static int MAX=1000; //Cantidad Máxima de Nodos
  static ArrayList<Integer> ady[] = new ArrayList[MAX]; //Lista de Adyacencia del grafo
  
  public static void main( String [] args ){
    int v, e, origen, destino;
    Scanner sc = new Scanner( System.in );
    
    v = sc.nextInt();
    e = sc.nextInt();
    
    init();
    
    while( e > 0 ){
      origen = sc.nextInt();
      destino = sc.nextInt();
      
      ady[ origen ].add( destino );
      ady[ destino ].add( origen );
      e--;
    }
  }
  
  static void init(){
    int i;
    for( i = 0; i < v; i++ ){
      ady[i] = new ArrayList<Integer>();
    }
  }
}
