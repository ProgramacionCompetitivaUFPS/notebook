Algoritmo para hallar componentes fuertemente conexas(SCC) en grafos dirigidos.

int v, e; 
static int n = 5000; // Máxima cantidad de nodos
static int dfs_low[] = new int[n];
static int dfs_num[] = new int[n];
static boolean visited[] = new boolean[n];
static Stack<Integer> s;
static int dfsCont, cantSCC;
static ArrayList<Integer> ady[] = new ArrayList[n];
	
public static void main (String[] args) throws java.lang.Exception{
	cantSCC = 0;

    for( int i = 0; i < v; i++ ){ //Por si el grafo no es conexo
        if( dfs_num[i] == -1 ){
            dfsCont = 0;
            s = new Stack<Integer>();
            tarjanSCC(i);
        }
    }
}
	
public static void tarjanSCC( int u ){
	dfs_low[u] = dfs_num[u] = dfsCont;
	dfsCont++;
	s.push(u);
	visited[u] = true;
		
	int j, v;
		
	for( j = 0; j < ady[u].size(); j++ ){
		v = ady[u].get( j );
			
		if( dfs_num[v] == -1 ){
			tarjanSCC( v );
		}
			
		if( visited[v] ){
			dfs_low[u] = Math.min( dfs_low[u], dfs_low[v] );
		}
	}
		
	if( dfs_low[u] == dfs_num[u] ){
		cantSCC++;
        /* ********************************************************* */
        /* Esta seccion se usa para imprimir las componentes conexas */
		System.out.println("COMPONENTE CONEXA #" + cantSCC );
		while( !s.empty() ){
			v = s.peek();
			s.pop();
			visited[v] = false;
			System.out.println(v);
			if( u == v ) break;
		}
        /* ********************************************************** */
	}
		
}


