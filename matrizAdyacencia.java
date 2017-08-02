import java.util.*;

public class Main{
  
  static int v, e; //v = cantidad de nodos, e = cantidad de aristas
  static int MAX=1000; //Cantidad Máxima de Nodos
  static int ady[][] = new int [MAX][MAX];
  
  public static void main( String [] args ){
    int v, e, origen, destino;
    Scanner sc = new Scanner( System.in );
    
    v = sc.nextInt();
    e = sc.nextInt();
    
    init();
    
    while( e > 0 ){
      origen = sc.nextInt();
      destino = sc.nextInt();
      
      ady[ origen ][ destino ] = 1;
      ady[ origen ][ destino ] = 1;
      e--;
    }
  }
  
  static void init(){
    int i, j;
    for( i = 0; i < v; i++ ){
      for( j = 0; j < v; j++ ){
        ady[i][j] = 0;
      }
    }
  }
}
