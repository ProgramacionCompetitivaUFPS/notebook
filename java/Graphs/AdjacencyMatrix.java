import java.util.*;

public class Main{
  
  static int v, e; //v = cantidad de nodos, e = cantidad de aristas
  static int MAX=1000; //Cantidad Máxima de Nodos
  static int ady[][] = new int [MAX][MAX];
  
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
      
      ady[ origen ][ destino ] = 1;
      ady[ destino ][ origen ] = 1;
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
